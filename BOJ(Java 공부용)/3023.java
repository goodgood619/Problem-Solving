import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[2 * n][2 * m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }

        for (int i = 0, k = 0; i < n; i++, k++) {
            for (int j = m - 1, p = m; j >= 0; j--, p++) {
                board[k][p] = board[i][j];
            }
        }

        for (int j = 0, p = 0; j < 2 * m; j++, p++) {
            for (int i = n - 1, k = n; i >= 0; i--, k++) {
                board[k][p] = board[i][j];
            }
        }

        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
        x--;
        y--;
        if (board[x][y] == '#') board[x][y] = '.';
        else board[x][y] = '#';

        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * m; j++) {
                bw.write(board[i][j]);
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}