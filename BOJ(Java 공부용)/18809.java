import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), g = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        List<Integer> v = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 2) v.add(i * m + j);
            }
        }

        boolean[] visited = new boolean[v.size()];
        go(0, 0, g + r, v, temp, visited, g, r, board);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void go(int here, int cnt, int depth, List<Integer> v, List<Integer> temp, boolean[] visited, int g, int r, int[][] board) {
        if (cnt == depth) {
            List<Integer> v2 = new ArrayList<>();
            boolean[] rvisited = new boolean[temp.size()];
            chooseRed(0, 0, r, temp, v2, g, board, rvisited);
            return;
        }
        for (int i = here; i < v.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.add(v.get(i));
                go(i + 1, cnt + 1, depth, v, temp, visited, g, r, board);
                temp.remove(temp.size() - 1);
                visited[i] = false;
            }
        }
    }

    private static void chooseRed(int here, int cnt, int depth, List<Integer> v, List<Integer> temp, int g, int[][] board, boolean[] visited) {
        if (cnt == depth) {
            List<Integer> green = new ArrayList<>();
            for (int i = 0; i < v.size(); i++) {
                if (!visited[i]) green.add(v.get(i));
            }
            makeFlower(temp, green, board, depth, g);
            return;
        }
        for (int i = here; i < v.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.add(v.get(i));
                chooseRed(i + 1, cnt + 1, depth, v, temp, g, board, visited);
                temp.remove(temp.size() - 1);
                visited[i] = false;
            }
        }
    }

    private static void makeFlower(List<Integer> red, List<Integer> green, int[][] board, int r, int g) {
        // 방문을 하긴하는데, 예외적인 처리가 방문한곳을 가는데, 이동거리가 같으면 꽃이 방문되었다 체크를 해야한다
        int n = board.length, m = board[0].length;
        boolean[][] flower = new boolean[n][m];
        int[][][] dist = new int[n][m][2];
        boolean[][] visited = new boolean[n][m];
        Queue<P> q = new ArrayDeque<>();
        for (Integer here : red) {
            int x = here / m, y = here % m;
            q.add(new P(x, y, true));
            visited[x][y] = true;
        }
        for (Integer here : green) {
            int x = here / m, y = here % m;
            q.add(new P(x, y, false));
            visited[x][y] = true;
        }

        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            boolean color = q.peek().color;
            q.poll();
            if (flower[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 0) continue;
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.add(new P(nx, ny, color));
                    int three = 0;
                    if (!color) three = 1;
                    dist[nx][ny][three] = dist[x][y][three] + 1;
                    continue;
                }
                if (color) {
                    if (dist[nx][ny][0] != 0) continue;
                    int nexttime = dist[x][y][0] + 1;
                    if (dist[nx][ny][1] == nexttime) {
                        flower[nx][ny] = true;
                    }
                } else {
                    if (dist[nx][ny][1] != 0) continue;
                    int nexttime = dist[x][y][1] + 1;
                    if (dist[nx][ny][0] == nexttime) {
                        flower[nx][ny] = true;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (flower[i][j]) cnt++;
            }
        }
        ans = Math.max(ans, cnt);
    }
}

class P {
    int x, y;
    boolean color;

    P(int x, int y, boolean color) {
        this.x = x;
        this.y = y;
        this.color = color;
    }
}