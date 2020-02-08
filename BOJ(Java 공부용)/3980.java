import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int[][] board = new int[11][11];
            boolean[] visited = new boolean[11];
            for (int i = 0; i < 11; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 11; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            ans = 0;
            go(0, 0, 11, 0, board, visited);
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static void go(int index, int cnt, int depth, int sum, int[][] board, boolean[] visited) {
        if (cnt == depth) {
            ans = max(ans, sum);
            return;
        }
        for (int i = 0; i < 11; i++) {
            if (board[index][i] == 0) continue;
            if (!visited[i]) {
                visited[i] = true;
                go(index + 1, cnt + 1, depth, sum + board[index][i], board, visited);
                visited[i] = false;
            }
        }
    }
}