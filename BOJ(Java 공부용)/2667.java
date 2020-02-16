import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][] board = new char[n][n];
        boolean[][] visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == '1') {
                    ans.add(dfs(i, j, board, visited, n));
                }
            }
        }

        bw.write(ans.size() + "\n");
        Collections.sort(ans);
        for (int i = 0; i < ans.size(); i++) bw.write(ans.get(i) + "\n");
        bw.flush();
        bw.close();
    }

    private static int dfs(int x, int y, char[][] board, boolean[][] visited, int n) {
        int ret = 1;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || board[nx][ny] == '0') continue;
            ret += dfs(nx, ny, board, visited, n);
        }
        return ret;
    }
}