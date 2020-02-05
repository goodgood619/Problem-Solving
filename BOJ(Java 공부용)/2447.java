import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][n];
        go(0,0,n,board);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                bw.write(board[i][j]=='*'?'*':' ');
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
   private static void go(int x, int y, int width,char[][] board) {
        if (width == 1) {
            board[x][y] = '*';
            return;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                go(x + i * width / 3, y + j * width / 3, width / 3,board);
            }
        }
    }
}