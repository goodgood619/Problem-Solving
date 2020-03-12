import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()), zr = Integer.parseInt(st.nextToken()), zc = Integer.parseInt(st.nextToken());
        char[][] board = new char[r][c];
        char[][] newboard = new char[r * zr][c * zc];
        for (int i = 0; i < r; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (int sx = i * zr, p = 0; p < zr; p++, sx++) {
                    for (int sy = j * zc, q = 0; q < zc; q++, sy++) {
                        newboard[sx][sy] = board[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < r * zr; i++) {
            for (int j = 0; j < c * zc; j++) {
                bw.write(newboard[i][j]);
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}