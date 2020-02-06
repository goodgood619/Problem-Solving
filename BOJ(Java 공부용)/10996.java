import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) System.out.println('*');
        else {
            char[][] board = new char[2 * n + 1][n + 1];
            int i = 0;
            for (int j = 1; j <= n; j++) {
                boolean check = false;
                if (j % 2 == 1) check = false;
                else check = true;
                if (!check) i = 1;
                else i = 2;
                for (; i <= 2 * n; i += 2) {
                    board[i][j] = '*';
                }
            }
            for (int j = 1; j <= 2 * n; j++) {
                for (int k = 1; k <= n; k++) {
                    if(board[j][k]=='\0') bw.write(" ");
                    else bw.write(board[j][k]);
                }
                bw.write("\n");
            }
            bw.flush();
            bw.close();
        }
    }
}