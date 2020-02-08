import java.io.*;
import java.util.*;

import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        boolean[] visited = new boolean[n * m];
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 0) v.add(i * m + j);
            }
        }
        dfs(0, 0, 3, board, v, visited, n, m);
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }

    private static void dfs(int index, int cnt, int depth, int[][] board, ArrayList<Integer> v, boolean[] visited, int n, int m) {
        if (cnt == depth) {
            ans = max(ans, bfs(board, n, m));
            return;
        }
        for (int i = index; i < v.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                int x = v.get(i) / m;
                int y = v.get(i) % m;
                board[x][y] = 1;
                dfs(i + 1, cnt + 1, depth, board, v, visited, n, m);
                visited[i] = false;
                board[x][y] = 0;
            }
        }
    }

    private static int bfs(int[][] board, int n, int m) {
        int[][] tempboard = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tempboard[i][j] = board[i][j];
            }
        }
        ArrayDeque<p> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tempboard[i][j] == 2) {
                    q.add(new p(i, j));
                    visited[i][j] = true;
                }
            }
        }

        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || tempboard[nx][ny] == 1 || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                tempboard[nx][ny] = 2;
                q.add(new p(nx, ny));
            }
        }
        int rest = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tempboard[i][j] == 0) rest++;
            }
        }
        return rest;
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}