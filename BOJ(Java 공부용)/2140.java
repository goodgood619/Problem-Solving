import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0,1,1,-1,-1};
    static int[] goy = {1,0,0,-1,1,-1,1,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        char[][] board = new char[n][n];
        if(n <3) {
            System.out.println(0);
            return;
        }
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            for(int j=0;j<s.length();j++) {
                board[i][j] = s.charAt(j);
            }
        }
        int possible = (n-2)*(n-2);
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<n-1;j++) {
                boolean no = false;
                for(int k=0;k<8;k++) {
                    int nx = i+gox[k], ny = j+goy[k];
                    if(board[nx][ny] == '0') {
                        no = true;
                        break;
                    }
                }
                if(no) possible--;
                else {
                    for(int k=0;k<8;k++) {
                        int nx = i+gox[k], ny = j+goy[k];
                        if(board[nx][ny] == '#') continue;
                        board[nx][ny]-=1;
                    }
                }
            }
        }
        System.out.println(possible);
    }
}