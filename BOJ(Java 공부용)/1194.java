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
        int sx = 0, sy = 0;
        ArrayList<p> end = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                board[i][j] = s.charAt(j);
                if (board[i][j] == '0') {
                    sx = i;
                    sy = j;
                }
                if (board[i][j] == '1') {
                    end.add(new p(i, j));
                }
            }
        }

        System.out.println(bfs(sx, sy, board, end, n, m));
    }

    private static int bfs(int sx, int sy, char[][] board, ArrayList<p> end, int n, int m) {
        ArrayDeque<pp> q = new ArrayDeque<>();
        q.add(new pp(sx, sy, 0));
        int[][][] dist = new int[n][m][1 << 6];
        boolean[][][] visited = new boolean[n][m][1 << 6];
        visited[sx][sy][0] = true;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int key = q.peek().key;
            q.poll();
            for (int i = 0; i < end.size(); i++) {
                if (x == end.get(i).x && y == end.get(i).y) {
                    return dist[x][y][key];
                }
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i];
                int ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny][key] || board[nx][ny] == '#') continue;
                if (board[nx][ny] >= 'A' && board[nx][ny] <= 'F') { //문
                    int check = key & (1 << (board[nx][ny] - 'A'));
                    if (check != 0) {
                        dist[nx][ny][key] = dist[x][y][key] + 1;
                        visited[nx][ny][key] = true;
                        q.add(new pp(nx, ny, key));
                    }
                } else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'f') { //열쇠
                    int newkey = key | (1 << (board[nx][ny] - 'a'));
                    dist[nx][ny][newkey] = dist[x][y][key] + 1;
                    q.add(new pp(nx, ny, newkey));
                    visited[nx][ny][newkey] = true;
                } else { //평지
                    dist[nx][ny][key] = dist[x][y][key] + 1;
                    visited[nx][ny][key] = true;
                    q.add(new pp(nx, ny, key));
                }
            }
        }
        return -1;
    }

    private static class pp {
        int x, y, key;

        private pp(int x, int y, int key) {
            this.x = x;
            this.y = y;
            this.key = key;
        }
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}