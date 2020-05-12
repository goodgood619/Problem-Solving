import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = (int) -1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        List<Integer> v = new ArrayList<>();
        boolean[] visited = new boolean[n * m];
        go(0, 0, k, board, v, n * m, visited, m);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void go(int here, int cnt, int depth, int[][] board, List<Integer> v, int total, boolean[] visited, int m) {
        if (cnt == depth) {
            int sum = 0;
            for (int i = 0; i < v.size(); i++) {
                int fx = v.get(i) / m, fy = v.get(i) % m;
                sum += board[fx][fy];
                for (int j = i + 1; j < v.size(); j++) {
                    int x = v.get(i) / m, y = v.get(i) % m, nx = v.get(j) / m, ny = v.get(j) % m;
                    if (Math.abs(x - nx) + Math.abs(y - ny) <= 1) return;
                }
            }
            ans = Math.max(ans, sum);
            return;
        }
        for (int i = here; i < total; i++) {
            if (!visited[i]) {
                visited[i] = true;
                v.add(i);
                go(i + 1, cnt + 1, depth, board, v, total, visited, m);
                v.remove(v.size() - 1);
                visited[i] = false;
            }
        }
    }
}