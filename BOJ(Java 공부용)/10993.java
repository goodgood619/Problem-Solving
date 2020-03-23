import java.io.*;

import static java.lang.StrictMath.pow;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][] board = new char[2000][3000];
        int sx = -1, sy = -1;
        if (n % 2 == 1) {
            sx = (int) (pow(2, n) - 1);
            sy = (int) (pow(2, n) - 1);
        } else {
            sx = 1;
            sy = (int) pow(2, n) - 1;
        }
        go(sx, sy, board, n, n);
    }

    private static void go(int sx, int sy, char[][] board, int n, int origin) throws IOException {
        if (n == 1) {
            board[sx][sy] = '*';
            int cnt = (int) pow(2, origin);
            cnt--;
            if(origin%2==0) {
                int p = cnt * 2;
                for (int i = 1; i <= cnt; i++) {
                    for (int j = 1; j <= p; j++) {
                        bw.write(board[i][j] == '*' ? '*' : ' ');
                    }
                    p--;
                    if (i != cnt) bw.write("\n");
                }
            }
            else {
                int p = cnt;
                for (int i = 1; i <= cnt; i++) {
                    for (int j = 1; j <= p; j++) {
                        bw.write(board[i][j] == '*' ? '*' : ' ');
                    }
                    p++;
                    if (i != cnt) bw.write("\n");
                }
            }
            bw.flush();
            bw.close();
            System.exit(0);
        }
        int px = sx, py = sy, lx = 0, ly = 0, rx = 0, ry = 0, ex = 0, ey = 0;
        int cnt = (int) (pow(2, n) - 1);
        int p = cnt;
        while (p-- > 1) {
            board[px][py] = '*';
            px += gox[3];
            py += goy[3];
            lx = px;
            ly = py;
        }
        px = sx;
        py = sy;
        p = cnt;
        while (p-- > 1) {
            board[px][py] = '*';
            px += gox[0];
            py += goy[0];
            rx = px;
            ry = py;
        }
        if (n % 2 == 0) {
            p = cnt;
            while (p-- > 0) {
                board[lx][ly] = '*';
                lx += gox[1];
                ly += goy[0];
            }
            p = cnt;
            while (p-- > 0) {
                board[rx][ry] = '*';
                rx += gox[1];
                ry += goy[3];
                ex = rx;
                ey = ry;
            }
        } else {
            p = cnt;
            while (p-- > 0) {
                board[lx][ly] = '*';
                lx += gox[2];
                ly += goy[0];
            }
            p = cnt;
            while (p-- > 0) {
                board[rx][ry] = '*';
                rx += gox[2];
                ry += goy[3];
                ex = rx;
                ey = ry;
            }
            ex++;
        }

        go((sx + ex) / 2, sy, board, n - 1, origin);
    }
}