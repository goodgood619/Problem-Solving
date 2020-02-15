import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int level = 2, sx = 0, sy = 0, eat = 0;
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 9) {
                    sx = i;
                    sy = j;
                }
            }
        }
        int time = 0;
        while (true) {
            ArrayList<p> v = new ArrayList<>();
            bfs(sx, sy, board, v, n, level);
            v.sort((a, b) -> {
                if (a.dist < b.dist) return -1;
                else if (a.dist > b.dist) return 1;
                else {
                    if (a.x < b.x) return -1;
                    else if (a.x > b.x) return 1;
                    else {
                        if (a.y < b.y) return -1;
                        else if (a.y > b.y) return 1;
                        else return 0;
                    }
                }
            });

            if (v.size() == 0) break;

            eat++;
            time += v.get(0).dist;
            if (level == eat) {
                level++;
                eat = 0;
            }
            int nx = v.get(0).x, ny = v.get(0).y;
            board[nx][ny] = 9;
            board[sx][sy] = 0;
            sx = nx;
            sy = ny;
        }
        bw.write(time + " ");
        bw.flush();
        bw.close();

    }

    private static void bfs(int sx, int sy, int[][] board, ArrayList<p> v, int n, int level) {
        boolean[][] visited = new boolean[n][n];
        visited[sx][sy] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy, 0));
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int dist = q.peek().dist;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || level < board[nx][ny]) continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny, dist + 1));
                if (level > board[nx][ny] && board[nx][ny] != 0) {
                    v.add(new p(nx, ny, dist + 1));
                }
            }
        }
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