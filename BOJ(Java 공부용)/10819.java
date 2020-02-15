import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        boolean[] visited = new boolean[n];
        ArrayList<Integer> v = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());

        go(0, n, visited, arr, v);
        System.out.println(ans);
    }

    private static void go(int cnt, int depth, boolean[] visited, int[] arr, ArrayList<Integer> v) {
        if (cnt == depth) {
            int sum = 0;
            for (int i = 0; i < v.size() - 1; i++) {
                sum += abs(v.get(i) - v.get(i + 1));
            }
            ans = max(ans, sum);
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                v.add(arr[i]);
                go(cnt + 1, depth, visited, arr, v);
                v.remove(v.size() - 1);
                visited[i] = false;
            }
        }
    }
}