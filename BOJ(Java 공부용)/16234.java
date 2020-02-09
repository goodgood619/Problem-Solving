import java.io.*;
import java.util.*;

import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int cnt = 0;
        while (true) {
            boolean[][] visited = new boolean[n][n];
            ArrayList<ArrayList<p>> temp = new ArrayList<>();
            int union = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!visited[i][j]) {
                        ArrayList<p> v = new ArrayList<>();
                        dfs(i, j, n, visited, board, v, l, r);
                        union++;
                        temp.add(v);
                    }
                }
            }
            //인구이동 더이상 안함
            if (union == n * n) break;

            for (int i = 0; i < temp.size(); i++) {
                ArrayList<p> list = temp.get(i);
                int sum = 0;
                for (int j = 0; j < list.size(); j++) {
                    int x = list.get(j).x, y = list.get(j).y;
                    sum += board[x][y];
                }
                sum /= list.size();
                for (int j = 0; j < list.size(); j++) {
                    int x = list.get(j).x, y = list.get(j).y;
                    board[x][y] = sum;
                }
            }
            cnt++;
        }
        System.out.println(cnt);
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void dfs(int x, int y, int n, boolean[][] visited, int[][] board, ArrayList<p> v, int l, int r) {
        visited[x][y] = true;
        v.add(new p(x, y));
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || abs(board[x][y] - board[nx][ny]) < l || abs(board[x][y] - board[nx][ny]) > r)
                continue;
            dfs(nx, ny, n, visited, board, v, l, r);
        }
    }

}