import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) System.out.println('*');
        else {
            char[][] board = new char[4 * n - 2][4 * n - 2];
            int sx = 2 * n - 1;
            int sy = sx;
            board[sx][sy] = '*';
            for (int i = 1; i <= n - 1; i++) {
                int weight = 2 * i;
                int x = sx - weight;
                int y = sy - weight;
                int j = 0;
                for (int k = 1; k <= 2 * weight + 1; k++) {
                    board[x][y] = '*';
                    y++;
                }
                y--;
                for (int k = 1; k <= 2 * weight + 1; k++) {
                    board[x][y] = '*';
                    x++;
                }
                x--;
                for (int k = 1; k <= 2 * weight + 1; k++) {
                    board[x][y] = '*';
                    y--;
                }
                y++;
                for (int k = 1; k <= 2 * weight + 1; k++) {
                    board[x][y] = '*';
                    x--;
                }
                x++;
            }
            for (int j = 1; j <= 4 * n - 3; j++) {
                for (int k = 1; k <= 4 * n - 3; k++) {
                    if (board[j][k] == '\0') bw.write(" ");
                    else bw.write(board[j][k]);
                }
                bw.write("\n");
            }
            bw.flush();
            bw.close();
        }
    }
}