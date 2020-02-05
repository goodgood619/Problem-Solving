import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][2*n];
        go(n,0,n-1,board);
        for(int i=0;i<n;i++) {
            for(int j=0;j<2*n;j++) {
                bw.write(board[i][j]=='*'?'*':' ');
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
    private static void go(int n,int x,int y,char[][] board) {
        if (n == 3) {
            int cnt = 1;
            for (int i = x; i <= x + 2; i++) {
                int here = 2 * cnt - 1;
                int j = y - cnt + 1;
                while (here-- > 0) {
                    if (i == x + 1 && j == y) {
                        j++;
                        continue;
                    }
                    board[i][j] = '*';
                    j++;
                }
                cnt++;
            }
            return;
        }
        go(n / 2, x, y,board);
        go(n / 2, x + n / 2, y - n / 2,board);
        go(n / 2, x + n / 2, y + n / 2,board);
    }
}