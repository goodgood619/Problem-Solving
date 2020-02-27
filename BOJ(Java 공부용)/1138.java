import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        boolean[] visited = new boolean[n];
        ArrayList<Integer> v = new ArrayList<>();
        go(0, n, visited, v, arr);
    }

    private static void go(int cnt, int depth, boolean[] visited, ArrayList<Integer> v, int[] arr) throws IOException {
        if (cnt == depth) {
            for (int i = 0; i < arr.length; i++) {
                int num = arr[i], idx = 0;
                for (int j = 0; j < v.size(); j++) {
                    if (i == v.get(j)) {
                        idx = j;
                        break;
                    }
                }
                for (int j = 0; j < v.size(); j++) {
                    if (j == idx) continue;
                    if (i < v.get(j) && idx > j) {
                        num--;
                    }
                }
                if (num != 0) return;
            }
            for (int i = 0; i < v.size(); i++) bw.write((v.get(i) + 1) + " ");
            bw.flush();
            bw.close();
            System.exit(0);
        }
        for (int i = 0; i < visited.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                v.add(i);
                go(cnt + 1, depth, visited, v, arr);
                v.remove(v.size() - 1);
                visited[i] = false;
            }
        }
    }
}