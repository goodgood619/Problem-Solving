import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] ngox = {-2, -2, 1, 1, 2, 2, -1, -1};
    static int[] ngoy = {-1, 1, -2, 2, -1, 1, 2, -2};
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};
    static int[] bgox = {1, 1, -1, -1};
    static int[] bgoy = {1, -1, 1, -1};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][n];
        Deque<P> q = new ArrayDeque<>();
        boolean[][][][] visited = new boolean[n][n][n * n + 1][3];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 1) {
                    q.add(new P(i, j, 1, 0));
                    q.add(new P(i, j, 1, 1));
                    q.add(new P(i, j, 1, 2));
                    visited[i][j][1][0] = true;
                    visited[i][j][1][1] = true;
                    visited[i][j][1][2] = true;
                }
            }
        }
        bw.write(bfs(board, q, visited, n) + "");
        bw.flush();
        bw.close();
    }

    private static int bfs(int[][] board, Deque<P> q, boolean[][][][] visited, int n) {
        int[][][][] dist = new int[n][n][n * n + 1][3];
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int num = q.peek().num;
            int choice = q.peek().choice;
            q.poll();
            if (num == n * n) {
                ans = Math.min(ans, dist[x][y][num][choice]);
            }
            //change
            for (int i = 0; i < 3; i++) {
                if (choice == i) continue;
                if (!visited[x][y][num][i]) {
                    visited[x][y][num][i] = true;
                    dist[x][y][num][i] = dist[x][y][num][choice] + 1;
                    q.add(new P(x, y, num, i));
                }
            }
            // 나이트
            if (choice == 0) {
                for (int i = 0; i < 8; i++) {
                    int nx = x + ngox[i], ny = y + ngoy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    int nextnum = num;
                    if (board[nx][ny] == num + 1) {
                        nextnum = num + 1;
                    }
                    if (!visited[nx][ny][nextnum][choice]) {
                        visited[nx][ny][nextnum][choice] = true;
                        q.add(new P(nx, ny, nextnum, choice));
                        dist[nx][ny][nextnum][choice] = dist[x][y][num][choice] + 1;
                    }
                }
            }
            // 룩
            else if (choice == 1) {
                for (int i = 0; i < 4; i++) {
                    for (int k = 1; ; k++) {
                        int nx = x + k * gox[i], ny = y + k * goy[i];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
                        int nextnum = num;
                        if (board[nx][ny] == num + 1) {
                            nextnum = num + 1;
                        }
                        if (!visited[nx][ny][nextnum][choice]) {
                            visited[nx][ny][nextnum][choice] = true;
                            q.add(new P(nx, ny, nextnum, choice));
                            dist[nx][ny][nextnum][choice] = dist[x][y][num][choice] + 1;
                        }
                    }
                }
            }
            // 비숍
            else {
                for (int i = 0; i < 4; i++) {
                    for (int k = 1; ; k++) {
                        int nx = x + k * bgox[i], ny = y + k * bgoy[i];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
                        int nextnum = num;
                        if (board[nx][ny] == num + 1) {
                            nextnum = num + 1;
                        }
                        if (!visited[nx][ny][nextnum][choice]) {
                            visited[nx][ny][nextnum][choice] = true;
                            q.add(new P(nx, ny, nextnum, choice));
                            dist[nx][ny][nextnum][choice] = dist[x][y][num][choice] + 1;
                        }
                    }
                }
            }
        }
        return ans;
    }


}

class P {
    int x, y, num, choice;

    P(int x, int y, int num, int choice) {
        this.x = x;
        this.y = y;
        this.num = num;
        this.choice = choice;
    }
}