import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][][] board = new char[n][5][7];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                String s = br.readLine();
                for (int k = 0; k < s.length(); k++) {
                    board[i][j][k] = s.charAt(k);
                }
            }
        }
        int ans = (int) 1e9, one = 0, two = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ans > go(i, j, board)) {
                    ans = go(i, j, board);
                    one = i + 1;
                    two = j + 1;
                }
            }
        }
        bw.write(one + " " + two + "\n");
        bw.flush();
        bw.close();
    }

    private static int go(int x, int y, char[][][] board) {
        int diff = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[x][i][j] != board[y][i][j]) diff++;
            }
        }
        return diff;
    }
}