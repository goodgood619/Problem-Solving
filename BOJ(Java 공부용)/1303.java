import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }
        int white = 0, blue = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    int cnt = dfs(i, j, visited, board, board[i][j], n, m);
                    if (board[i][j] == 'W') white += cnt * cnt;
                    else blue += cnt * cnt;
                }
            }
        }

        System.out.println(white + " " + blue);
    }

    private static int dfs(int x, int y, boolean[][] visited, char[][] board, char c, int n, int m) {
        visited[x][y] = true;
        int ret = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] != c) continue;
            ret += dfs(nx, ny, visited, board, c, n, m);
        }
        return ret;
    }
}