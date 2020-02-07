import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[] fact = new long[21];
        boolean[] visited = new boolean[21];
        ArrayList<Integer> v = new ArrayList<>();
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i <= 20; i++) fact[i] = i * fact[i - 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int choice = Integer.parseInt(st.nextToken());
        if (choice == 1) {
            long k = Long.parseLong(st.nextToken());
            go(n, k, fact, visited, v, n);
        } else {
            for (int i = 0; i < n; i++) {
                v.add(Integer.parseInt(st.nextToken()));
            }
            go2(0, n, 1, fact, visited, v, n);
        }
    }

    private static void go2(int index, int s, long sum, long[] fact, boolean[] visited, ArrayList<Integer> v, int n) throws IOException {
        if (index == v.size()) {
            bw.write(sum + " ");
            bw.flush();
            bw.close();
            System.exit(0);
        }
        long p = fact[s - 1];
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            if (v.get(index) == i) {
                visited[i] = true;
                go2(index + 1, s - 1, sum, fact, visited, v, n);
            } else sum += p;
        }
    }

    private static void go(int p, long k, long[] fact, boolean[] visited, ArrayList<Integer> temp, int n) throws IOException {
        long here = fact[p - 1];
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) temp.add(i);
            }
            for (int i = 0; i < temp.size(); i++) bw.write(temp.get(i) + " ");
            bw.flush();
            bw.close();
            System.exit(0);
        }
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            if (!visited[i] && k <= here) {
                visited[i] = true;
                temp.add(i);
                go(p - 1, k, fact, visited, temp, n);
            } else k -= here;
        }
    }
}