import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()) ,m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        boolean[][] visited = new boolean[n][m];
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(make(n,m,board,visited));
    }
    private static void dfs(int x, int y,boolean[][] visited,int n,int m,int[][] board) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i];
            int ny = y + goy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || board[nx][ny] == 0) continue;
            dfs(nx, ny,visited,n,m,board);
        }
    }
    private static int make(int n,int m,int[][] board,boolean[][] visited) {
        for (int p = 1;; p++) {
            int zero = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if(board[j][k] == 0) zero++;
                }
            }
            if (zero == n * m) break;
            boolean[][] ice = new boolean[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == 0) continue;
                    else {
                        for (int k = 0; k < 4; k++) {
                            int nx = i + gox[k];
                            int ny = j + goy[k];
                            if (nx<0 || nx>=n || ny<0 || ny>=m || ice[nx][ny] || board[nx][ny] != 0) continue;
                            else if (board[nx][ny] == 0) {
                                board[i][j]--;
                                if (board[i][j] < 0) board[i][j] = 0;
                                ice[i][j] = true;
                            }
                        }
                    }
                }
            }

            int cnt = 0;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++){
                    visited[i][j] = false;
                }
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (!visited[j][k] && board[j][k] != 0) {
                        for(int q=0;q<n;q++) {
                            for(int r=0;r<m;r++) {
                                visited[q][r] = false;
                            }
                        }
                        dfs(j, k,visited,n,m,board);
                        cnt++;
                    }
                }
            }
            if (cnt >= 2) return p;
        }
        return 0;
    }
}