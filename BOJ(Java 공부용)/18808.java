import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        List<int[][]> sticker = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            int[][] temp = new int[r][c];
            for (int j = 0; j < r; j++) {
                st = new StringTokenizer(br.readLine());
                for (int p = 0; p < c; p++) {
                    temp[j][p] = Integer.parseInt(st.nextToken());
                }
            }
            sticker.add(temp);
        }

        for (int[][] e : sticker) {
            int r = e.length;
            int c = e[0].length;

            // 1번
            if (first(n, m, board, e, r, c)) {
                continue;
            }
            //2번(돌리기)
            for (int i = 0; i < 3; i++) {
                int[][] temp;
                if (i == 0) {
                    temp = new int[c][r];
                    for (int a = 0, q = 0; a < c; a++, q++) {
                        for (int b = 0, p = r - 1; b < r; b++, p--) {
                            temp[a][b] = e[p][q];
                        }
                    }
                    if (first(n, m, board, temp, c, r)) {
                        break;
                    }
                } else if (i == 1) {
                    temp = new int[r][c];
                    for (int a = 0, p = r - 1; a < r; a++, p--) {
                        for (int b = 0, q = c - 1; b < c; b++, q--) {
                            temp[a][b] = e[p][q];
                        }
                    }
                    if (first(n, m, board, temp, r, c)) {
                        break;
                    }
                } else {
                    temp = new int[c][r];
                    for (int a = 0, q = c - 1; a < c; a++, q--) {
                        for (int b = 0, p = 0; b < r; b++, p++) {
                            temp[a][b] = e[p][q];
                        }
                    }
                    if (first(n, m, board, temp, c, r)) {
                        break;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1) cnt++;
            }
        }

        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }

    private static boolean first(int n, int m, int[][] board, int[][] sticker, int r, int c) {
        int ex = n - r, ey = m - c;
        if (ex < 0 || ey < 0) return false;
        int x = 0, y = 0;
        boolean ok = false;
        while (true) {
            if (x > ex) break;
            int p = x;
            int q = y;
            boolean no = false;
            for (int i = 0, a = p; i < r; i++, a++) {
                for (int j = 0, b = q; j < c; j++, b++) {
                    if (board[a][b] == 1 && sticker[i][j] == 1) {
                        no = true;
                    }
                }
            }
            if (!no) { //맞는것이 존재
                for (int i = x, a = 0; i < x + r; i++, a++) {
                    for (int j = y, b = 0; j < y + c; j++, b++) {
                        if (sticker[a][b] == 1 && board[i][j] == 0)
                            board[i][j] = sticker[a][b];
                    }
                }
                ok = true;
                break;
            }
            if (y == ey) {
                y = 0;
                x++;
            } else y++;
        }

        return ok;
    }
}