import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
        boolean[] visited = new boolean[n];
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());

        ArrayList<Integer> temp = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            go(0, 0, i, visited, arr, temp, l, r, x);
        }
        System.out.println(ans);
    }

    private static void go(int index, int cnt, int depth, boolean[] visited, int[] arr, ArrayList<Integer> temp, int l, int r, int x) {
        if (cnt == depth) {
            int sum = 0;
            ArrayList<Integer> temp2 = new ArrayList<>(temp);
            Collections.sort(temp2);
            for (int i = 0; i < temp2.size(); i++) {
                sum += temp2.get(i);
            }
            if (sum < l || sum > r || temp2.get(temp2.size() - 1) - temp2.get(0) < x) return;
            ans++;
            return;
        }
        for (int i = index; i < visited.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.add(arr[i]);
                go(i + 1, cnt + 1, depth, visited, arr, temp, l, r, x);
                temp.remove(temp.size() - 1);
                visited[i] = false;

            }
        }
    }
}