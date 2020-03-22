import java.io.*;
import java.util.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][n];
        List<Integer> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                v.add(i * n + j);
            }
        }
        List<Integer> temp = new ArrayList<>();
        boolean[] visited = new boolean[v.size()];
        go(0, 0, 3, v, visited, temp, n, board);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void go(int index, int cnt, int depth, List<Integer> v, boolean[] visited, List<Integer> temp, int n, int[][] board) {
        if (cnt == depth) {
            Map<p, Integer> map = new HashMap<>();
            for (int num : temp) {
                int x = num / n, y = num % n;
                p p = new p(x, y);
                if (map.get(p) == null) {
                    map.put(p, 1);
                } else {
                    return;
                }
                for (int j = 0; j < 4; j++) {
                    int nx = x + gox[j], ny = y + goy[j];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) return;
                    p np = new p(nx, ny);
                    if (map.get(np) == null) {
                        map.put(np, 1);
                    } else {
                        return;
                    }
                }
            }
            int sum = 0;
            for (p e : map.keySet()) {
                int x = e.x, y = e.y;
                sum += board[x][y];
            }
            ans = min(ans, sum);
            return;
        }
        for (int i = index; i < v.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.add(v.get(i));
                go(i + 1, cnt + 1, depth, v, visited, temp, n, board);
                temp.remove(temp.size() - 1);
                visited[i] = false;
            }
        }
    }
}

class p {
    int x, y;

    p(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        p p = (p) o;
        return x == p.x &&
                y == p.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}