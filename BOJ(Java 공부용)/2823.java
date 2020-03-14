import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int counter = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + gox[k], ny = j + goy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'X') continue;
                        cnt++;
                    }
                    if (cnt <= 1) {
                        bw.write("1");
                        bw.flush();
                        bw.close();
                        return;
                    }
                }
            }
        }
        bw.write("0");
        bw.flush();
        bw.close();
    }
}