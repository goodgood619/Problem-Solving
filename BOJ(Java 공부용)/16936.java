import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] arr = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        TreeMap<Long, Integer> map = new TreeMap<>();
        ArrayList<Long> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
            map.put(arr[i], 1);
        }
        for (int i = 0; i < n; i++) {
            v.add(arr[i]);
            go(arr[i], 1, n, map, v);
            v.remove(v.size() - 1);
        }

    }

    private static void go(long here, int cnt, int depth, TreeMap<Long, Integer> map, ArrayList<Long> v) throws IOException {
        if (map.get(here) == null) return;
        if (cnt == depth) {
            for (int i = 0; i < v.size(); i++) bw.write(v.get(i) + " ");
            bw.flush();
            bw.close();
            System.exit(0);
        }
        if (here % 3 == 0) {
            v.add(here / 3);
            go(here / 3, cnt + 1, depth, map, v);
            v.remove(v.size() - 1);
        }
        v.add(here * 2);
        go(here * 2, cnt + 1, depth, map, v);
        v.remove(v.size() - 1);
    }
}