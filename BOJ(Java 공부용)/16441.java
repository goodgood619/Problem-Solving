import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;

class Main {
    static int[] gox = {1,0,-1,0};
    static int[] goy = {0,1,0,-1};
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        char[][] board = new char[n][m];
        boolean[][] visited = new boolean[n][m];
        Deque<P> q = new ArrayDeque<>();
        for(int i= 0;i<n;i++) {
            String s = br.readLine();
            for(int j = 0 ; j <s.length();j++) {
                board[i][j] = s.charAt(j);
                if (board[i][j] == 'W') {
                    q.add(new P(i,j));
                }
            }
        }

        bfs(board,q,visited);


    }
    private static void bfs(char[][] board, Deque<P> q, boolean[][] visited) throws IOException {
        int n = board.length;
        int m = board[0].length;

        while(!q.isEmpty()) {
            int x = q.peekFirst().x;
            int y = q.peekFirst().y;
            q.pollFirst();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i];
                int ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == '#') continue;

                if (board[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    q.add(new P(nx,ny));
                }
                else if (board[nx][ny] == '+') {
                    int tx = nx;
                    int ty = ny;
                    while (tx + gox[i] >=0 && tx + gox[i] <n && ty + goy[i] >= 0 && ty+goy[i] < m) {
                        if (board[tx][ty] == '#' || board[tx][ty] == '.') {
                            break;
                        }
                        tx += gox[i];
                        ty += goy[i];
                    }

                    if (board[tx][ty] == '#') {
                        tx -= gox[i];
                        ty -= goy[i];
                        if (!visited[tx][ty]) {
                            visited[tx][ty] = true;
                            q.add(new P(tx,ty));
                        }
                    }
                    if (board[tx][ty] == '.') {
                        if (!visited[tx][ty]) {
                            visited[tx][ty] = true;
                            q.add(new P(tx,ty));
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == '.') {
                    bw.write("P");
                }
                else bw.write(board[i][j]);
            }
            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }

    static class P {
        int x,y;
        P(int x,int y ) {
            this.x = x;
            this.y = y;
        }
    }
}