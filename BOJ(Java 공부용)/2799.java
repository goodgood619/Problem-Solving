import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[5 * n + 1][5 * m + 1];
        for (int i = 0; i < 5 * n + 1; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }
        int one = 0, two = 0, three = 0, four = 0, five = 0;
        for (int i = 1; i < 5 * n + 1; i += 5) {
            for (int j = 1; j < 5 * m + 1; j += 5) {
                int res = go(i, j, board);
                if (res == 0) one++;
                if (res == 4) two++;
                if (res == 8) three++;
                if (res == 12) four++;
                if (res == 16) five++;
            }
        }

        bw.write(one + " " + two + " " + three + " " + four + " " + five);
        bw.flush();
        bw.close();
    }

    private static int go(int x, int y, char[][] board) {
        int count = 0;
        for (int i = x; i < x + 4; i++) {
            for (int j = y; j < y + 4; j++) {
                if (board[i][j] == '*') count++;
            }
        }
        return count;
    }
}