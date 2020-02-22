import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String s1 = st.nextToken(), s2 = st.nextToken();
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    go(i, j, s1, s2);
                    return;
                }
            }
        }
    }

    private static void go(int i, int j, String s1, String s2) throws IOException {
        char[][] board = new char[s2.length()][s1.length()];
        for (int x = 0; x < s2.length(); x++) {
            for (int y = 0; y < s1.length(); y++) {
                board[x][y] = '.';
            }
        }
        for (int y = 0; y < s1.length(); y++) board[j][y] = s1.charAt(y);
        for (int x = 0; x < s2.length(); x++) board[x][i] = s2.charAt(x);
        for (int x = 0; x < s2.length(); x++) {
            for (int y = 0; y < s1.length(); y++) {
                bw.write(board[x][y]);
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}