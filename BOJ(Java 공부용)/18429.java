import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        List<Integer> v = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) v.add(Integer.parseInt(st.nextToken()));
        List<Integer> temp = new ArrayList<>();
        boolean[] visited = new boolean[v.size()];
        go(0, n, k, v, temp, visited);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void go(int cnt, int depth, int k, List<Integer> v, List<Integer> temp, boolean[] visited) {
        if (cnt == depth) {
            int start = 500;
            for (int i = 0; i < temp.size(); i++) {
                int diff = temp.get(i) - k;
                start += diff;
                if (start < 500) return;
            }
            ans++;
            return;
        }
        for (int i = 0; i < v.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.add(v.get(i));
                go(cnt + 1, depth, k, v, temp, visited);
                temp.remove(temp.size() - 1);
                visited[i] = false;
            }
        }
    }
}