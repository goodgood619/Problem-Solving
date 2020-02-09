import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][n];
        ArrayList<p> v = new ArrayList<>();
        PriorityQueue<pp> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else {
                    if (a.next < b.next) return -1;
                    else if (a.next > b.next) return 1;
                    else return 0;
                }
            }
        });

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
                if (board[i][j] == 'S' || board[i][j] == 'K') {
                    v.add(new p(i, j));
                }
            }
        }

        for (int i = 0; i < v.size(); i++) {
            bfs(v.get(i), i, n, v, board, pq);
        }

        int[] parent = new int[m + 2];
        for (int i = 0; i < m + 2; i++) parent[i] = i;
        int cnt = 0, ans = 0;
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int next = pq.peek().next;
            int cost = pq.peek().cost;
            pq.poll();
            if (find(here, parent) != find(next, parent)) {
                union(here, next, parent);
                cnt++;
                ans += cost;
            }
        }
        if (cnt == v.size() - 1) bw.write(ans + " ");
        else bw.write("-1");
        bw.flush();
        bw.close();
    }

    private static int find(int u, int[] parent) {
        if (parent[u] == u) return parent[u];
        return parent[u] = find(parent[u], parent);
    }

    private static void union(int u, int v, int[] parent) {
        u = find(u, parent);
        v = find(v, parent);
        if (u == v) return;
        parent[u] = v;
    }

    private static void bfs(p a, int here, int n, ArrayList<p> v, char[][] board, PriorityQueue<pp> pq) {
        boolean[][] visited = new boolean[n][n];
        int[][] dist = new int[n][n];
        visited[a.x][a.y] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(a.x, a.y));
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || board[nx][ny] == '1') continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
                if (board[nx][ny] == 'S' || board[nx][ny] == 'K') {
                    int idx = -1;
                    for (int j = 0; j < v.size(); j++) {
                        if (nx == v.get(j).x && ny == v.get(j).y) {
                            idx = j;
                            break;
                        }
                    }
                    pq.add(new pp(here, idx, dist[nx][ny]));
                }
            }
        }
    }

    private static class pp {
        int here, next, cost;

        private pp(int here, int next, int cost) {
            this.here = here;
            this.next = next;
            this.cost = cost;
        }
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}