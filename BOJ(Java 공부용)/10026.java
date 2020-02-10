import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][] board = new char[n][n];
        boolean[][] visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }
        int cnt = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    dfs(i, j, board, visited, n);
                    cnt++;
                }
            }
        }
        visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    dfs2(i, j, board, visited, n, board[i][j]);
                    cnt2++;
                }
            }
        }
        bw.write(cnt + " " + cnt2 + "\n");
        bw.flush();
        bw.close();
    }

    private static void dfs(int x, int y, char[][] board, boolean[][] visited, int n) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || board[x][y] != board[nx][ny]) continue;
            dfs(nx, ny, board, visited, n);
        }
    }

    private static void dfs2(int x, int y, char[][] board, boolean[][] visited, int n, char c) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            if (c == 'R' || c == 'G') {
                if (board[nx][ny] != 'B') dfs2(nx, ny, board, visited, n, c);
            }
            if (c == 'B') {
                if (board[nx][ny] == 'B') dfs2(nx, ny, board, visited, n, c);
            }
        }
    }
}