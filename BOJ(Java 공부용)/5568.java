import java.io.*;
import java.util.HashMap;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }
        boolean[] visited = new boolean[arr.length];
        StringBuilder sb = new StringBuilder();
        HashMap<Integer, Integer> m = new HashMap<>();
        go(0, k, arr, visited, sb, m);
        System.out.println(m.size());

    }

    private static void go(int cnt, int depth, String[] arr, boolean[] visited, StringBuilder sb, HashMap<Integer, Integer> m) {
        if (cnt == depth) {
            int num = Integer.parseInt(sb.toString());
            m.putIfAbsent(num, 1);
            return;
        }
        for (int i = 0; i < visited.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sb.append(arr[i]);
                go(cnt + 1, depth, arr, visited, sb, m);
                visited[i] = false;
                sb.delete(sb.length() - arr[i].length(), sb.length());
            }
        }
    }
}