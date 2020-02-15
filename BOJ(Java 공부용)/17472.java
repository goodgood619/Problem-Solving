import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        boolean[][] visited = new boolean[n][m];
        ArrayList<ArrayList<p>> nation = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 1) {
                    ArrayList<p> temp = new ArrayList<>();
                    dfs(i, j, visited, board, temp, n, m);
                    nation.add(temp);
                }
            }
        }
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

        for (int i = 0; i < nation.size(); i++) {
            for (int j = 0; j < nation.get(i).size(); j++) {
                int x = nation.get(i).get(j).x, y = nation.get(i).get(j).y;

                for (int k = 0; k < 4; k++) {
                    int tx = x, ty = y, move = 0;

                    while (check(tx + gox[k], ty + goy[k], n, m) && board[tx + gox[k]][ty + goy[k]] == 0) {
                        tx += gox[k];
                        ty += goy[k];
                        move++;
                    }
                    if (move == 1) continue;
                    tx += gox[k];
                    ty += goy[k];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;

                    int next = find(tx, ty, nation);
                    pq.add(new pp(i, next, move));
                }
            }
        }
        int ans = 0, cnt = 0;
        int[] parent = new int[nation.size()];
        for (int i = 0; i < nation.size(); i++) parent[i] = i;
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int next = pq.peek().next;
            int cost = pq.peek().cost;
            pq.poll();
            if (find2(here, parent) != find2(next, parent)) {
                union(here, next, parent);
                ans += cost;
                cnt++;
            }
        }

        System.out.println(ans == 0 || cnt != nation.size() - 1 ? -1 : ans);
    }

    private static void union(int u, int v, int[] parent) {
        u = find2(u, parent);
        v = find2(v, parent);
        if (u == v) return;
        parent[u] = v;
    }

    private static int find2(int u, int[] parent) {
        if (u == parent[u]) return u;
        return parent[u] = find2(parent[u], parent);
    }

    private static class pp {
        int here, next, cost;

        private pp(int here, int next, int cost) {
            this.here = here;
            this.next = next;
            this.cost = cost;
        }
    }

    private static int find(int x, int y, ArrayList<ArrayList<p>> nation) {
        for (int i = 0; i < nation.size(); i++) {
            for (int j = 0; j < nation.get(i).size(); j++) {
                int tx = nation.get(i).get(j).x, ty = nation.get(i).get(j).y;
                if (tx == x && ty == y) return i;
            }
        }
        return 0;
    }

    private static boolean check(int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m) return false;
        return true;
    }

    private static void dfs(int x, int y, boolean[][] visited, int[][] board, ArrayList<p> temp, int n, int m) {
        visited[x][y] = true;
        temp.add(new p(x, y));
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == 0) continue;
            dfs(nx, ny, visited, board, temp, n, m);
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