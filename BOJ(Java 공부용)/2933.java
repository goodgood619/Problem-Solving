import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }
        int k = Integer.parseInt(br.readLine());
        int[] arr = new int[k];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) arr[i] = Integer.parseInt(st.nextToken());
        bfs(board, arr, n, m);
    }

    private static void bfs(char[][] board, int[] arr, int n, int m) throws IOException {

        for (int p = 0; p < arr.length; p++) {
            boolean[][] visited = new boolean[n][m];
            int hit = arr[p];
            erase(hit, p, board, n, m);
            for (int j = 0; j < m; j++) {
                if (board[n - 1][j] == 'x') {
                    dfs(n - 1, j, board, visited, n, m);
                }
            }
            down(visited, board, n, m);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bw.write(board[i][j]);
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    //모양이 유지되면서 다운된다흠
    private static void down(boolean[][] visited, char[][] board, int n, int m) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'x') {
                    ArrayList<p> v = new ArrayList<>();
                    boolean[][] visited2 = new boolean[n][m];
                    dfs2(i, j, board, visited2, n, m, v);
                    ArrayList<Integer>[] cluster = new ArrayList[m + 1];
                    ArrayList<Integer>[] movedown = new ArrayList[m + 1];
                    for (int k = 0; k <= m; k++) {
                        cluster[k] = new ArrayList<>();
                        movedown[k] = new ArrayList<>();
                    }
                    for (int k = 0; k < v.size(); k++) {
                        cluster[v.get(k).y].add(v.get(k).x);
                    }
                    for (int k = 0; k <= m; k++) {
                        cluster[k].sort(Comparator.reverseOrder());
                    }

                    for (int p = 1; ; p++) {
                        boolean check = false;
                        int okcnt = 0;
                        for (int k = 0; k < v.size(); k++) {
                            int x = v.get(k).x, y = v.get(k).y;
                            if (x + p < n && visited2[x + p][y]) {
                                okcnt++;
                                continue;
                            }
                            if (x + p < n && board[x + p][y] != 'x') {
                                okcnt++;
                            } else {
                                check = true;
                                break;
                            }
                        }
                        if (okcnt != v.size()) {
                            p--;
                            for (int k = 0; k < cluster.length; k++) {
                                if (cluster[k].size() == 0) continue;
                                for (int r = 0; r < cluster[k].size(); r++) {
                                    int x = cluster[k].get(r), y = k;
                                    board[x + p][y] = 'x';
                                    board[x][y] = '.';
                                }
                            }
                            break;
                        }
                    }

                    return;
                }
            }
        }
    }

    private static void dfs2(int x, int y, char[][] board, boolean[][] visited, int n, int m, ArrayList<p> v) {
        visited[x][y] = true;
        v.add(new p(x, y));
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == '.') continue;
            dfs2(nx, ny, board, visited, n, m, v);
        }
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void dfs(int x, int y, char[][] board, boolean[][] visited, int n, int m) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == '.') continue;
            dfs(nx, ny, board, visited, n, m);
        }
    }

    private static void erase(int pos, int p, char[][] board, int n, int m) {
        if (p % 2 == 0) {
            pos = n - pos;
            int y = -1, move = 0;
            while (y + goy[0] < m && board[pos + gox[0]][y + goy[0]] != 'x') {
                pos += gox[0];
                y += goy[0];
                move++;
            }
            if (move != m) {
                y += goy[0];
                board[pos][y] = '.';
            }

        } else {
            pos = n - pos;
            int y = m, move = 0;
            while (y + goy[3] >= 0 && board[pos + gox[3]][y + goy[3]] != 'x') {
                pos += gox[3];
                y += goy[3];
                move++;
            }
            if (move != m) {
                y += goy[3];
                board[pos][y] = '.';
            }
        }
    }
}