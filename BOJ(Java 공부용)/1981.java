import java.io.*;
import java.util.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][n];
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                set.add(board[i][j]);
            }
        }
        ArrayList<Integer> v = new ArrayList<>(set);
        Collections.sort(v);

        int left = 0, right = 0, ans = (int) 1e9;

        while (true) {
            if (left >= v.size() || right >= v.size()) break;
            boolean ok = false;
            while (true) {
                if (right >= v.size() || left >= v.size()) break;
                if (bfs(v.get(left), v.get(right), board, n)) {
                    ok = true;
                    break;
                } else right++;
            }
            if (ok) {
                ans = min(ans, v.get(right) - v.get(left));
                left++;
            }
        }
        System.out.println(ans);
    }

    private static boolean bfs(int low, int high, int[][] board, int n) {
        boolean[][] visited = new boolean[n][n];
        if (board[0][0] < low || board[0][0] > high) return false;
        visited[0][0] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(0, 0, board[0][0]));
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int num = q.peek().num;
            if (x == n - 1 && y == n - 1) {
                return true;
            }
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || board[nx][ny] < low || board[nx][ny] > high)
                    continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny, board[nx][ny]));
            }
        }
        return false;
    }

    private static class p {
        int x, y, num;

        private p(int x, int y, int num) {
            this.x = x;
            this.y = y;
            this.num = num;
        }
    }
}