import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        int rx = 0, ry = 0, bx = 0, by = 0, gx = 0, gy = 0;
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
                if (board[i][j] == 'R') {
                    rx = i;
                    ry = j;
                }
                if (board[i][j] == 'B') {
                    bx = i;
                    by = j;
                }
                if (board[i][j] == 'O') {
                    gx = i;
                    gy = j;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        int ans = bfs(rx, ry, bx, by, gx, gy, n, m, board, sb);
        if (ans >= 1e9) bw.write("-1");
        else bw.write(ans + "\n" + sb.toString());
        bw.flush();
        bw.close();
    }

    private static int bfs(int rx, int ry, int bx, int by, int gx, int gy, int n, int m, char[][] board, StringBuilder sb) {
        boolean[][][][] visited = new boolean[n][m][n][m];
        ArrayDeque<p> q = new ArrayDeque<>();
        StringBuilder sbc = new StringBuilder();
        q.add(new p(rx, ry, bx, by, 0, sbc));
        visited[rx][ry][bx][by] = true;
        while (!q.isEmpty()) {
            int currx = q.peek().rx;
            int curry = q.peek().ry;
            int curbx = q.peek().bx;
            int curby = q.peek().by;
            int cnt = q.peek().cnt;
            StringBuilder cursb = q.peek().sb;
            if (currx == gx && curry == gy) {
                sb.append(cursb);
                return cnt;
            }
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nrx = currx, nry = curry, nbx = curbx, nby = curby, rmove = 0, bmove = 0;
                while (board[nrx + gox[i]][nry + goy[i]] != '#' && board[nrx][nry] != 'O') {
                    nrx += gox[i];
                    nry += goy[i];
                    rmove++;
                }
                while (board[nbx + gox[i]][nby + goy[i]] != '#' && board[nbx][nby] != 'O') {
                    nbx += gox[i];
                    nby += goy[i];
                    bmove++;
                }
                if (nbx == gx && nby == gy) continue;
                if (nrx == nbx && nry == nby) {
                    if (rmove > bmove) {
                        nrx -= gox[i];
                        nry -= goy[i];
                    } else {
                        nbx -= gox[i];
                        nby -= goy[i];
                    }
                }
                if (visited[nrx][nry][nbx][nby]) continue;
                if (cnt < 10) {
                    StringBuilder newsb = new StringBuilder();
                    newsb.append(cursb);
                    if (i == 0) q.add(new p(nrx, nry, nbx, nby, cnt + 1, newsb.append('R')));
                    if (i == 1) q.add(new p(nrx, nry, nbx, nby, cnt + 1, newsb.append('D')));
                    if (i == 2) q.add(new p(nrx, nry, nbx, nby, cnt + 1, newsb.append('U')));
                    if (i == 3) q.add(new p(nrx, nry, nbx, nby, cnt + 1, newsb.append('L')));
                    visited[nrx][nry][nbx][nby] = true;
                }
            }
        }
        return (int) 1e9;
    }

    private static class p {
        int rx, ry, bx, by, cnt;
        StringBuilder sb;

        private p(int rx, int ry, int bx, int by, int cnt, StringBuilder sb) {
            this.rx = rx;
            this.ry = ry;
            this.bx = bx;
            this.by = by;
            this.cnt = cnt;
            this.sb = sb;
        }
    }


}