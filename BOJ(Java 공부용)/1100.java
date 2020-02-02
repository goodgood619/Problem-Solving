import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[][] board = new char[8][8];
        for(int i=0;i<8;i++) {
            String s = br.readLine();
            for(int j=0;j<s.length();j++) {
                board[i][j] = s.charAt(j);
            }
        }

        boolean check = false;
        int cnt = 0;
        for(int i=0;i<8;i++) {
            if (i != 0) {
                if (!check) check = true;
                else check = false;
            }
            for (int j = 0; j < 8; j++) {
                if (!check) {
                    if (board[i][j] == 'F') cnt++;
                    check = true;
                }
                else {
                    check = false;
                }
            }
        }
        System.out.println(cnt);
    }
}