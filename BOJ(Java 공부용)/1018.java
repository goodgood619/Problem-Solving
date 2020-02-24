import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

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
        int ans = (int) 1e9;
        for (int i = 0; i < n - 7; i++) {
            for (int j = 0; j < m - 7; j++) {
                for (int temp = 0; temp < 2; temp++) {
                    int cnt = 0;
                    ArrayList<Character> v = new ArrayList<>();
                    if (temp == 0) {
                        v.add('B');
                        v.add('W');
                    } else {
                        v.add('W');
                        v.add('B');
                    }
                    for (int k = i; k < i + 8; k++) {
                        for (int p = j; p < j + 8; p++) {
                            if (v.get((k + p) % 2) != board[k][p]) cnt++;
                        }
                    }
                    ans = min(ans, cnt);
                }
            }
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }
}