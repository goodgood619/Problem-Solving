import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] board = new int[5][5];
        for (int i = 0; i < 5; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < 5; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                int num = Integer.parseInt(st.nextToken());
                if (go(board, num)) {
                    System.out.println(i * 5 + j + 1);
                    return;
                }
            }
        }
    }

    private static boolean go(int[][] board, int num) {

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == num) {
                    board[i][j] = 0;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < 5; i++) {
            int zero = 0;
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == 0) zero++;
            }
            if (zero == 5) total++;
        }
        for (int j = 0; j < 5; j++) {
            int zero = 0;
            for (int i = 0; i < 5; i++) {
                if (board[i][j] == 0) zero++;
            }
            if (zero == 5) total++;
        }
        int zero1 = 0;
        for (int i = 0, j = 0; i < 5; i++, j++) if (board[i][j] == 0) zero1++;
        if (zero1 == 5) total++;
        zero1 = 0;
        for (int i = 4, j = 0; i >= 0; i--, j++) if (board[i][j] == 0) zero1++;
        if (zero1 == 5) total++;
        if (total >= 3) return true;
        else return false;
    }
}