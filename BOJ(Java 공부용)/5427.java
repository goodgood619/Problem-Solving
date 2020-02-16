import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
            char[][] board = new char[n + 2][m + 2];
            boolean[][] visited = new boolean[n + 2][m + 2];
            boolean[][] fvisited = new boolean[n + 2][m + 2];
            ArrayDeque<p> q = new ArrayDeque<>();
            ArrayDeque<p> fq = new ArrayDeque<>();
            for (int i = 1; i <= n; i++) {
                String s = br.readLine();
                for (int j = 0; j < s.length(); j++) {
                    if (s.charAt(j) == ' ') break;
                    board[i][j + 1] = s.charAt(j);
                    if (board[i][j + 1] == '@') {
                        q.add(new p(i, j + 1, 1));
                        visited[i][j + 1] = true;
                    }
                    if (board[i][j + 1] == '*') {
                        fq.add(new p(i, j + 1, 0));
                        fvisited[i][j + 1] = true;
                    }
                }
            }

            bfs(board, q, fq, n, m, visited, fvisited);
        }
        bw.flush();
        bw.close();
    }

    private static void bfs(char[][] board, ArrayDeque<p> q, ArrayDeque<p> fq, int n, int m, boolean[][] visited, boolean[][] fvisited) throws IOException {

        while (true) {
            ArrayDeque<p> tempfq = new ArrayDeque<>();
            ArrayDeque<p> tempq = new ArrayDeque<>();
            while (!fq.isEmpty()) {
                int x = fq.peek().x;
                int y = fq.peek().y;
                fq.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + gox[i], ny = y + goy[i];
                    if (nx <= 0 || nx > n || ny <= 0 || ny > m || fvisited[nx][ny] || board[nx][ny] == '#') continue;
                    tempfq.add(new p(nx, ny, 0));
                    fvisited[nx][ny] = true;
                }
            }

            while (!q.isEmpty()) {
                int x = q.peek().x;
                int y = q.peek().y;
                int dist = q.peek().dist;
                q.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + gox[i], ny = y + goy[i];
                    if (nx <= 0 || nx > n || ny <= 0 || ny > m) {
                        bw.write(dist + "\n");
                        return;
                    }
                    if (fvisited[nx][ny] || visited[nx][ny] || board[nx][ny] == '#') continue;
                    visited[nx][ny] = true;
                    tempq.add(new p(nx, ny, dist + 1));
                }
            }
            if (tempq.isEmpty()) break;
            while (!tempfq.isEmpty()) {
                fq.add(tempfq.peekFirst());
                tempfq.poll();
            }
            while (!tempq.isEmpty()) {
                q.add(tempq.peekFirst());
                tempq.poll();
            }
        }
        bw.write("IMPOSSIBLE\n");
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