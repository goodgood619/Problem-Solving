import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

import static java.lang.Math.pow;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        boolean[][] fvisit = new boolean[n][m];
        boolean[][] visit = new boolean[n][m];
        int sx = 0, sy = 0;
        ArrayDeque<p> fire = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                board[i][j] = s.charAt(j);
                if (board[i][j] == 'J') {
                    sx = i;
                    sy = j;
                    visit[sx][sy] = true;
                } else if (board[i][j] == 'F') {
                    fvisit[i][j] = true;
                    fire.add(new p(i, j));
                }
            }
        }
        if (n == 1 || m == 1) {
            System.out.println(1);
            return;
        }
        bfs(sx, sy, board, n, m, fvisit, visit, fire);
    }

    private static void bfs(int sx, int sy, char[][] board, int n, int m, boolean[][] fvisit, boolean[][] visit, ArrayDeque<p> fire) {
        visit[sx][sy] = true;
        //불을 퍼트린다, 그다음 지훈이가 이동한다
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy));
        int ans = 0;
        for (int i = 1; ; i++) {
            ArrayDeque<p> newfire = new ArrayDeque<>();
            ArrayDeque<p> newman = new ArrayDeque<>();
            while (!fire.isEmpty()) {
                int x = fire.peek().x;
                int y = fire.peek().y;
                fire.poll();
                for (int k = 0; k < 4; k++) {
                    int nx = x + gox[k], ny = y + goy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '#' || fvisit[nx][ny]) continue;
                    fvisit[nx][ny] = true;
                    newfire.add(new p(nx, ny));
                }
            }
            boolean ok = false;
            while (!q.isEmpty()) {
                int x = q.peek().x;
                int y = q.peek().y;
                q.poll();
                for (int k = 0; k < 4; k++) {
                    int nx = x + gox[k], ny = y + goy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        ok=true;
                        break;
                    }
                    if (visit[nx][ny] || board[nx][ny] == '#' || fvisit[nx][ny]) continue;
                    visit[nx][ny] = true;
                    newman.add(new p(nx, ny));
                }
                if (ok) break;
            }
            if (ok) {
                ans = i;
                break;
            }
            if (newman.size() == 0) break;
            q = newman;
            fire = newfire;
        }
        System.out.println(ans == 0 ? "IMPOSSIBLE" : ans);
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}