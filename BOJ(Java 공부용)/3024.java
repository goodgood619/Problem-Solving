import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                char c = check(i, j, board);
                if (c == ' ') continue;
                System.out.println(c);
                return;
            }
        }
        System.out.println("ongoing");
    }

    private static char check(int x, int y, char[][] board) {
        for (int i = x; i < x + 3; i++) {
            char c = board[i][y];
            int num = 0;
            if (c == '.') continue;
            for (int j = y; j < y + 3; j++) {
                if (c == board[i][j]) num++;
            }
            if (num == 3) return c;
        }

        for (int j = y; j < y + 3; j++) {
            char c = board[x][j];
            int num = 0;
            if (c == '.') continue;
            for (int i = x; i < x + 3; i++) {
                if (c == board[i][j]) num++;
            }
            if (num == 3) return c;
        }
        if (board[x][y] == board[x + 1][y + 1] && board[x + 1][y + 1] == board[x + 2][y + 2] && board[x][y] != '.') {
            return board[x][y];
        }
        if (board[x][y + 2] == board[x + 1][y + 1] && board[x + 1][y + 1] == board[x + 2][y] && board[x][y + 2] != '.') {
            return board[x][y + 2];
        }
        return ' ';
    }
}