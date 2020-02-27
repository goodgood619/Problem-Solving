import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            String s = br.readLine();
            char[][] board = new char[s.length() / n][n];
            int idx = 0;
            boolean check = false;
            for (int i = 0; i < s.length(); ) {
                String temp = s.substring(i, i + n);
                if (!check) for (int j = 0; j < n; j++) board[idx][j] = temp.charAt(j);
                else {
                    for (int j = n - 1, p = 0; j >= 0; j--, p++) board[idx][j] = temp.charAt(p);
                }
                idx++;
                i += temp.length();
                check = !check;
            }
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < s.length() / n; i++) {
                    System.out.print(board[i][j]);
                }
            }
            System.out.println();
        }
    }
}