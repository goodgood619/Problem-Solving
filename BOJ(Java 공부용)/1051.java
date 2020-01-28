import java.io.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int max = 1;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int[][] board = new int[n][m];
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            for(int j=0;j<s.length();j++) {
                board[i][j]= s.charAt(j)-'0';
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                go(i,j,board,1,n,m);
            }
        }
        bw.write(max+"\n");
        bw.flush();
        bw.close();
    }
    private static void go(int x,int y,int[][] board,int width,int n,int m) {
        int sx = x;
        int ex = x+width;
        int sy = y;
        int ey = y+width;
        if(ex >=n || ey>=m) return;
        else {
            go(x,y,board,width+1,n,m);
            if(board[sx][sy] == board[sx][ey]  && board[sx][ey] == board[ex][sy] && board[ex][sy] == board[ex][ey]) {
                max = max(max,(width+1)*(width+1));
            }
        }
    }
}