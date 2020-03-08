import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        int[][][][] dist = new int[n][m][k + 1][2];
        boolean[][][] visited = new boolean[n][m][k + 1];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                board[i][j] = s.charAt(j) - '0';
            }
        }
        bfs(0, 0, board, dist, visited, n, m, k);
    }

    private static void bfs(int sx, int sy, int[][] board, int[][][][] dist, boolean[][][] visited, int n, int m, int k) throws IOException {
        // 0 :낮, 1:밤
        visited[sx][sy][k] = true;
        dist[sx][sy][k][0] = 1;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy, k, 0));
        int ans = (int) 1e9;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int cnt = q.peek().cnt;
            int time = q.peek().time;
            if (x == n - 1 && y == m - 1) {
                ans = min(ans, dist[x][y][cnt][time]);
                break;
            }
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny][cnt]) continue;
                if (time == 0) {
                    if (board[nx][ny] == 1 && cnt > 0 && !visited[nx][ny][cnt - 1]) {
                        visited[nx][ny][cnt - 1] = true;
                        q.add(new p(nx, ny, cnt - 1, (time + 1) % 2));
                        dist[nx][ny][cnt - 1][(time + 1) % 2] = dist[x][y][cnt][time] + 1;
                    } else if (board[nx][ny] == 0 && !visited[nx][ny][cnt]) {
                        visited[nx][ny][cnt] = true;
                        q.add(new p(nx, ny, cnt, (time + 1) % 2));
                        dist[nx][ny][cnt][(time + 1) % 2] = dist[x][y][cnt][time] + 1;
                    } else if (!visited[x][y][cnt]) {
                        visited[x][y][cnt] = true;
                        q.add(new p(x, y, cnt, (time + 1) % 2));
                        dist[x][y][cnt][(time + 1) % 2] = dist[x][y][cnt][time] + 1;
                    }
                } else {
                    if (board[nx][ny] == 0 && !visited[nx][ny][cnt]) {
                        visited[nx][ny][cnt] = true;
                        q.add(new p(nx, ny, cnt, (time + 1) % 2));
                        dist[nx][ny][cnt][(time + 1) % 2] = dist[x][y][cnt][time] + 1;
                    } else if (board[nx][ny] == 1) {
                        q.add(new p(x, y, cnt, (time + 1) % 2));
                        dist[x][y][cnt][(time + 1) % 2] = dist[x][y][cnt][time] + 1;
                    }
                }
            }
        }
        bw.write(ans == 1e9 ? "-1" : ans + " ");
        bw.flush();
        bw.close();
        //낮일때, 벽을뚫던가, 그냥가던가, 밤일때는, 벽이아니면 이동은 가능

    }

    private static class p {
        int x, y, cnt, time;

        private p(int x, int y, int cnt, int time) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.time = time;
        }
    }
}