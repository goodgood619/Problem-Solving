import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
            }
        }

        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if (board[i][j] == '.') System.out.print('.');
                else if (board[i][j] == 'O') System.out.print('O');
                else if (board[i][j] == '-') System.out.print('|');
                else if (board[i][j] == '|') System.out.print('-');
                else if (board[i][j] == '/') System.out.print('\\');
                else if (board[i][j] == '\\') System.out.print('/');
                else if (board[i][j] == '^') System.out.print('<');
                else if (board[i][j] == '<') System.out.print('v');
                else if (board[i][j] == 'v') System.out.print('>');
                else if (board[i][j] == '>') System.out.print('^');
            }
            System.out.println();
        }
    }
}