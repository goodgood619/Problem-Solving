import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static double ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        double[] arr = new double[4];
        boolean[][] visited = new boolean[33][33];
        for (int i = 0; i < 4; i++) {
            arr[i] = Double.parseDouble(st.nextToken());
            arr[i] /= 100;
        }
        dfs(15, 15, 0, n, 1.0, visited, arr);
        System.out.print(String.format("%.9f", ans));
    }

    private static void dfs(int x, int y, int cnt, int depth, double sum, boolean[][] visited, double[] arr) {
        visited[x][y] = true;
        if (cnt == depth) {
            ans += sum;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (!visited[nx][ny]) {
                dfs(nx, ny, cnt + 1, depth, sum * arr[i], visited, arr);
                visited[nx][ny] = false;
            }
        }
    }

}