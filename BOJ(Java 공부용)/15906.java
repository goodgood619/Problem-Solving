import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), t = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
        r--;
        c--;
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }

        bfs(0, 0, r, c, board, n, t);
    }

    private static void bfs(int sx, int sy, int ex, int ey, char[][] board, int n, int t) {
        // mode : false(일반), true(변신), 0 : 일반, 1:변신
        Deque<P> q = new ArrayDeque<>();
        q.add(new P(sx, sy, false));
        boolean[][][] visited = new boolean[n][n][2];
        int[][][] dist = new int[n][n][2];
        visited[sx][sy][0] = true;
        int ans = (int) 1e9;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            boolean mode = q.peek().mode;
            q.poll();
            if (x == ex && y == ey) {
                if (mode) ans = Math.min(ans, dist[x][y][1]);
                else ans = Math.min(ans, dist[x][y][0]);
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                //일반모드, t턴을 소모하고서 변신을 하고 그 위치로 이동, 그냥 이동하던가
                if (!mode) {
                    int gateDist = find(x, y, i, board, n);
                    if (gateDist != 0) {
                        int nx2 = x + gateDist * gox[i], ny2 = y + gateDist * goy[i];
                        if (!visited[nx2][ny2][1]) {
                            visited[nx2][ny2][1] = true;
                            dist[nx2][ny2][1] = dist[x][y][0] + t + 1;
                            q.add(new P(nx2, ny2, true));
                        } else if (dist[nx2][ny2][1] > dist[x][y][0] + t + 1) {
                            dist[nx2][ny2][1] = dist[x][y][0] + t + 1;
                            q.add(new P(nx2, ny2, true));
                        }
                    }
                    if (!visited[nx][ny][0]) {
                        visited[nx][ny][0] = true;
                        dist[nx][ny][0] = dist[x][y][0] + 1;
                        q.add(new P(nx, ny, false));
                    } else if (dist[nx][ny][0] > dist[x][y][0] + 1) {
                        dist[nx][ny][0] = dist[x][y][0] + 1;
                        q.add(new P(nx, ny, false));
                    }
                }
                // 변신모드, 가장 가까운 게이트웨이를 찾으면 변신모드 유지하면서 넣어주고, 그냥 일반모드로 돌아갈수도 있으니 그냥 이동
                else {
                    int gateDist = find(x, y, i, board, n);
                    if (gateDist != 0) {
                        int nx2 = x + gateDist * gox[i], ny2 = y + gateDist * goy[i];
                        if (!visited[nx2][ny2][1]) {
                            visited[nx2][ny2][1] = true;
                            dist[nx2][ny2][1] = dist[x][y][1] + 1;
                            q.add(new P(nx2, ny2, true));
                        } else if (dist[nx2][ny2][1] > dist[x][y][1] + 1) {
                            dist[nx2][ny2][1] = dist[x][y][1] + 1;
                            q.add(new P(nx2, ny2, true));
                        }
                    }
                    // 일반모드 복귀
                    if (!visited[nx][ny][0]) {
                        visited[nx][ny][0] = true;
                        dist[nx][ny][0] = dist[x][y][1] + 1;
                        q.add(new P(nx, ny, false));
                    } else if (dist[nx][ny][0] > dist[x][y][1] + 1) {
                        dist[nx][ny][0] = dist[x][y][1] + 1;
                        q.add(new P(nx, ny, false));
                    }
                }
            }
        }
        System.out.println(ans);
    }

    private static int find(int x, int y, int dir, char[][] board, int n) {
        int cnt = 0;
        while (x + gox[dir] < n && x + gox[dir] >= 0 && y + goy[dir] < n && y + goy[dir] >= 0) {
            x += gox[dir];
            y += goy[dir];
            cnt++;
            if (board[x][y] == '#') break;
        }
        if (board[x][y] == '#') return cnt;
        else return 0;
    }

}

class P {
    int x, y;
    boolean mode;

    P(int x, int y, boolean mode) {
        this.x = x;
        this.y = y;
        this.mode = mode;
    }
}
