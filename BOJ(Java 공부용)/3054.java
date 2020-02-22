import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        char[][] board = new char[5][s.length() * 4 + 1];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < s.length() * 4 + 1; j++) {
                board[i][j] = '.';
            }
        }

        int x = 2;
        ArrayList<Integer> v = new ArrayList<>();
        for (int j = 2, i = 0; j < s.length() * 4 + 1; j += 4, i++) {
            if (i % 3 == 2) {
                board[x][j] = s.charAt(i);
                v.add(j);
                continue;
            }
            boolean[][] visited = new boolean[5][s.length() * 4 + 1];
            board[x][j] = s.charAt(i);
            dfs(x, j, board, 0, visited);
        }
        for (int i = 0; i < v.size(); i++) {
            boolean[][] visited = new boolean[5][s.length() * 4 + 1];
            dfs2(x, v.get(i), board, 0, visited);
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < s.length() * 4 + 1; j++) {
                bw.write(board[i][j]);
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    private static void dfs2(int x, int y, char[][] board, int dist, boolean[][] visited) {
        visited[x][y] = true;
        if (dist == 2) {
            board[x][y] = '*';
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (!visited[nx][ny]) dfs2(nx, ny, board, dist + 1, visited);
        }
    }

    private static void dfs(int x, int y, char[][] board, int dist, boolean[][] visited) {
        visited[x][y] = true;
        if (dist == 2) {
            board[x][y] = '#';
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (!visited[nx][ny]) dfs(nx, ny, board, dist + 1, visited);
        }
    }
}