import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[3][3];
        boolean[][] visited = new boolean[3][3];
        for (int i = 0; i < 3; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!visited[i][j] && board[i][j] >= '0' && board[i][j] <= '9') {
                    ArrayList<p> temp = new ArrayList<>();
                    dfs(i, j, n, m - 1, board, temp, board[i][j] - '0', visited);
                }
            }
        }
        System.out.println(0);
    }

    private static void dfs(int x, int y, int n, int m, char[][] board, ArrayList<p> temp, int sum, boolean[][] visited) throws IOException {
        temp.add(new p(x, y));
        if (sum == n && m == 0) {
            bw.write("1\n");
            for (int i = 0; i < temp.size(); i++) {
                bw.write(temp.get(i).x + " " + temp.get(i).y + "\n");
            }
            bw.flush();
            bw.close();
            System.exit(0);
        }
        visited[x][y] = true;
        boolean check = false;
        int cx = temp.get(temp.size() - 1).x, cy = temp.get(temp.size() - 1).y;
        if (board[cx][cy] >= '0' && board[cx][cy] <= '9') check = false;
        else check = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3 || visited[nx][ny]) continue;
            if (!check) {
                dfs(nx, ny, n, m, board, temp, sum, visited);
            } else {
                if (board[cx][cy] == '+') {
                    dfs(nx, ny, n, m - 1, board, temp, sum + (board[nx][ny] - '0'), visited);
                } else if (board[cx][cy] == '-') {
                    dfs(nx, ny, n, m - 1, board, temp, sum - (board[nx][ny] - '0'), visited);
                }
            }
        }
        visited[x][y] = false;
        temp.remove(temp.size() - 1);
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}