import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        TreeMap<Integer, Integer> m = new TreeMap<>();
        boolean[] visited = new boolean[n];
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            m.putIfAbsent(arr[i], 1);
        }
        for (int i = 1; i <= n; i++) {
            go(0, 0, 0, i, arr, visited, m);
        }
        Iterator it = m.keySet().iterator();
        int value = (int) it.next();
        if (value == 1) {
            while (it.hasNext()) {
                int next = (int) it.next();
                if (next - value == 1) {
                    value = next;
                    continue;
                } else {
                    System.out.println(value + 1);
                    return;
                }
            }
            System.out.println(value + 1);
        } else System.out.println(1);
    }

    private static void go(int index, int cnt, int sum, int depth, int[] arr, boolean[] visited, TreeMap<Integer, Integer> m) {
        if (cnt == depth) {
            m.putIfAbsent(sum, 1);
            return;
        }
        for (int i = index; i < arr.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                go(i + 1, cnt + 1, sum + arr[i], depth, arr, visited, m);
                visited[i] = false;
            }
        }
    }
}