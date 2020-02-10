import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        int sx = 0, sy = 0, ex = 0, ey = 0;
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
                if (board[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (board[i][j] == 'D') {
                    ex = i;
                    ey = j;
                }
            }
        }

        bfs(sx, sy, ex, ey, board, n, m);
    }

    private static void bfs(int sx, int sy, int ex, int ey, char[][] board, int n, int m) {
        boolean[][] visit = new boolean[n][m];
        boolean[][] watervisit = new boolean[n][m];
        ArrayDeque<p> waterq = new ArrayDeque<>();
        ArrayDeque<p> man = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '*') {
                    watervisit[i][j] = true;
                    waterq.add(new p(i, j, 0));
                }
            }
        }
        man.add(new p(sx, sy, 0));
        visit[sx][sy] = true;
        while (true) {
            ArrayDeque<p> tempwater = new ArrayDeque<>();
            ArrayDeque<p> tempman = new ArrayDeque<>();

            while (!waterq.isEmpty()) {
                int x = waterq.peek().x;
                int y = waterq.peek().y;
                int dist = waterq.peek().dist;
                waterq.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + gox[i], ny = y + goy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || watervisit[nx][ny] || board[nx][ny] == 'X' || board[nx][ny] == 'D')
                        continue;
                    tempwater.add(new p(nx, ny, dist + 1));
                    watervisit[nx][ny] = true;
                }
            }

            while (!man.isEmpty()) {
                int x = man.peek().x;
                int y = man.peek().y;
                int dist = man.peek().dist;
                if (x == ex && y == ey) {
                    System.out.println(dist);
                    System.exit(0);
                }
                man.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + gox[i], ny = y + goy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || watervisit[nx][ny] || board[nx][ny] == 'X')
                        continue;
                    visit[nx][ny] = true;
                    tempman.add(new p(nx, ny, dist + 1));
                }
            }


            if (tempman.size() == 0) break;
            while (!tempman.isEmpty()) {
                man.add(new p(tempman.peek().x, tempman.peek().y, tempman.peek().dist));
                tempman.poll();
            }
            while (!tempwater.isEmpty()) {
                waterq.add(new p(tempwater.peek().x, tempwater.peek().y, tempwater.peek().dist));
                tempwater.poll();
            }
        }
        System.out.println("KAKTUS");
    }


    private static class p {
        int x, y, dist;

        private p(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
}