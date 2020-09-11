import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());

        List<String> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            board.add(br.readLine());
        }
        boolean[][] visited = new boolean[n][m];
        dfs(n - 1, 0, 0, m - 1, visited, board, 1, k, n, m);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void dfs(int x, int y, int ex, int ey, boolean[][] visited, List<String> board, int dist, int endDist, int n, int m) {
        if (x == ex && y == ey) {
            if (dist == endDist) ans++;
            return;
        }
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || board.get(nx).charAt(ny) == 'T' || visited[nx][ny]) continue;
            dfs(nx, ny, ex, ey, visited, board, dist + 1, endDist, n, m);
        }
        visited[x][y] = false;
    }
}