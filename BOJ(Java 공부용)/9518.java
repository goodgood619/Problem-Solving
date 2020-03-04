import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1, 1, 1, -1, -1};
    static int[] goy = {1, -1, 0, 0, 1, -1, 1, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        boolean[][] visited = new boolean[n][m];
        int[][] dist = new int[n][m];
        int max = 0;
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }
        int sx = -1, sy = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'o') {
                    for (int k = 0; k < 8; k++) {
                        int nx = i + gox[k], ny = j + goy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'o') continue;
                        dist[nx][ny]++;
                        if (max < dist[nx][ny]) {
                            max = dist[nx][ny];
                            sx = nx;
                            sy = ny;
                        }
                    }
                }
            }
        }
        if (sx != -1 && sy != -1) board[sx][sy] = 'o';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'o' && !visited[i][j]) {
                    check(i, j, board, visited, n, m);
                }
            }
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }

    private static void check(int x, int y, char[][] board, boolean[][] visited, int n, int m) {
        visited[x][y] = true;
        for (int i = 0; i < 8; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == '.') continue;
            ans++;
        }
    }
}