import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[][] board = new char[12][6];
        for (int i = 0; i < 12; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }
        int ans = 0;
        while (true) {
            boolean[][] visited = new boolean[12][6];
            ArrayList<ArrayList<p>> remove = new ArrayList<>();
            for (int i = 11; i >= 0; i--) {
                for (int j = 0; j < 6; j++) {
                    if (!visited[i][j] && board[i][j] != '.') {
                        ArrayList<p> temp = new ArrayList<>();
                        dfs(i, j, board, visited, board[i][j], temp);
                        if (temp.size() >= 4) remove.add(temp);
                    }
                }
            }
            if (remove.size() == 0) break;
            for (int i = 0; i < remove.size(); i++) {
                for (int j = 0; j < remove.get(i).size(); j++) {
                    int x = remove.get(i).get(j).x, y = remove.get(i).get(j).y;
                    board[x][y] = '.';
                }
            }
            ans++;
            down(board);
        }
        System.out.println(ans);
    }

    private static void down(char[][] board) {
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] == '.') {
                    int p = i;
                    for (int k = i - 1; k >= 0; k--) {
                        if (board[k][j] != '.') {
                            board[p][j] = board[k][j];
                            board[k][j] = '.';
                            p--;
                        }
                    }
                }
            }
        }
    }

    private static void dfs(int x, int y, char[][] board, boolean[][] visited, char c, ArrayList<p> temp) {
        visited[x][y] = true;
        temp.add(new p(x, y));
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6 || visited[nx][ny] || board[nx][ny] != c) continue;
            dfs(nx, ny, board, visited, c, temp);
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