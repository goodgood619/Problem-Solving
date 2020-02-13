import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = (int) 1e9;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][n];
        boolean[][] visited = new boolean[n][n];
        ArrayList<ArrayList<p>> nation = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 1) {
                    ArrayList<p> v = new ArrayList<>();
                    dfs(i, j, visited, board, v, n);
                    nation.add(v);
                }
            }
        }


        for (int i = 0; i < nation.size(); i++) {
            bfs(nation.get(i), n, i, nation);
        }
        System.out.println(ans);
    }

    private static void bfs(ArrayList<p> mynation, int n, int index, ArrayList<ArrayList<p>> nation) {
        boolean[][] visited = new boolean[n][n];
        boolean[][] notvisited = new boolean[n][n];
        ArrayDeque<p> q = new ArrayDeque<>();
        for (int i = 0; i < mynation.size(); i++) {
            int x = mynation.get(i).x, y = mynation.get(i).y;
            visited[x][y] = true;
            q.add(new p(x, y));
        }

        for (int i = 0; i < nation.size(); i++) {
            if (index == i) continue;
            for (int j = 0; j < nation.get(i).size(); j++) {
                int x = nation.get(i).get(j).x, y = nation.get(i).get(j).y;
                notvisited[x][y] = true;
            }
        }


        for (int j = 1; ; j++) {
            ArrayDeque<p> temp = new ArrayDeque<>();
            boolean check = false;
            while (!q.isEmpty()) {
                int x = q.peek().x;
                int y = q.peek().y;
                q.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + gox[i], ny = y + goy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
                    if (notvisited[nx][ny]) {
                        check = true;
                        break;
                    }
                    visited[nx][ny] = true;
                    temp.add(new p(nx, ny));
                }
                if (check) break;
            }
            if (check) {
                ans = min(ans, j - 1);
                break;
            }

            while (!q.isEmpty()) q.poll();
            q = temp;
        }
    }

    private static void dfs(int x, int y, boolean[][] visited, int[][] board, ArrayList<p> v, int n) {
        visited[x][y] = true;
        v.add(new p(x, y));
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 0 || visited[nx][ny]) continue;
            dfs(nx, ny, visited, board, v, n);
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