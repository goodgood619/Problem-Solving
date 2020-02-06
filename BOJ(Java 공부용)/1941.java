import java.io.*;
import java.util.ArrayDeque;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[][] board = new char[5][5];
        boolean[][] visited = new boolean[5][5];
        for (int i = 0; i < 5; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                board[i][j] = s.charAt(j);
            }
        }
        dfs(0, 0, board, visited);
        bw.write(ans + "\n");
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, int cnt, char[][] board, boolean[][] visited) {
        if (here >= 25) return;
        if (cnt == 7) {
            ArrayDeque<p> q = new ArrayDeque<>();
            int yes = 0;
            boolean[][] check = new boolean[5][5];
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (visited[i][j]) {
                        check[i][j] = true;
                        q.add(new p(i, j));
                        yes = 1;
                        break;
                    }
                }
                if (yes == 1) break;
            }
            int cc = 1;
            while (!q.isEmpty()) {
                int x = q.peek().x;
                int y = q.peek().y;
                q.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + gox[i];
                    int ny = y + goy[i];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || !visited[nx][ny] || check[nx][ny]) continue;
                    else if (visited[nx][ny]) {
                        check[nx][ny] = true;
                        cc++;
                        q.add(new p(nx, ny));
                    }
                }
            }
            if (cc < 7) return;
            int s = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (visited[i][j]) {
                        if (board[i][j] == 'S') s++;
                    }
                }
            }
            if (s >= 4) ans++;
            return;
        }
        while (here < 25 && visited[here / 5][here % 5]) here++;
        if (here >= 25) return;
        visited[here / 5][here % 5] = true;
        dfs(here, cnt + 1, board, visited);
        visited[here / 5][here % 5] = false;
        dfs(here + 1, cnt, board, visited);
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}