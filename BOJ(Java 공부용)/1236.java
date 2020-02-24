import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        int[] row = new int[n];
        int[] col = new int[m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
                if (board[i][j] == 'X') {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (row[i] == 0) a++;
        }
        for (int j = 0; j < m; j++) {
            if (col[j] == 0) b++;
        }
        System.out.println(max(a, b));
    }
}