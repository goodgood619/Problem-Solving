import java.io.*;
import java.util.*;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][n];
        List<p> v = new ArrayList<>();
        List<p> temp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 2) {
                    v.add(new p(i, j));
                }
            }
        }
        boolean[] visited = new boolean[v.size()];
        dfs(0, 0, m, visited, board, v, temp, n);
        bw.write((ans == 1e9) ? "-1" : ans + " ");
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, int cnt, int depth, boolean[] visited, int[][] board, List<p> v, List<p> temp, int n) {
        if (cnt == depth) {
            ans = min(ans, bfs(temp, board, n));
            return;
        }
        for (int i = here; i < visited.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.add(v.get(i));
                dfs(i + 1, cnt + 1, depth, visited, board, v, temp, n);
                temp.remove(temp.size() - 1);
                visited[i] = false;
            }
        }
    }

    private static int bfs(List<p> v, int[][] board, int n) {
        boolean[][] visited = new boolean[n][n];
        Deque<pp> q = new ArrayDeque<>();
        for (int i = 0; i < v.size(); i++) {
            int x = v.get(i).x, y = v.get(i).y;
            visited[x][y] = true;
            q.add(new pp(x, y, 0));
        }
        int temp = 0;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int dist = q.peek().cost;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1 || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                if (board[nx][ny] != 2) {
                    temp = max(temp, dist + 1);
                }
                q.add(new pp(nx, ny, dist + 1));
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 0) {
                    return (int) 1e9;
                }
            }
        }

        return temp;
    }

    private static class pp {
        int x, y, cost;

        private pp(int x, int y, int cost) {
            this.x = x;
            this.y = y;
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