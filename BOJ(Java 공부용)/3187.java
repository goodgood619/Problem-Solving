import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static int sheep = 0, wolf = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                board[i][j] = s.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] != '#') {
                    bfs(i, j, visited, board, n, m);
                }
            }
        }
        System.out.println(sheep + " " + wolf);
    }

    private static void bfs(int sx, int sy, boolean[][] visited, char[][] board, int n, int m) {
        int tsheep = 0, twolf = 0;
        visited[sx][sy] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy));
        if (board[sx][sy] == 'k') tsheep++;
        if (board[sx][sy] == 'v') twolf++;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == '#') continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny));
                if (board[nx][ny] == 'k') tsheep++;
                if (board[nx][ny] == 'v') twolf++;
            }
        }

        if (tsheep > twolf) sheep += tsheep;
        else wolf += twolf;
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}