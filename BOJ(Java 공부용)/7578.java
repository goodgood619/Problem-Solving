import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int counter = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int h = 1;
        while (h < n) h <<= 1;
        int[] seg = new int[h * 2];
        st = new StringTokenizer(br.readLine());
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            map.put(Integer.parseInt(st.nextToken()), i);
        }
        st = new StringTokenizer(br.readLine());
        long sum = 0;
        for (int i = 1; i <= n; i++) {
            int index = map.get(Integer.parseInt(st.nextToken()));
            update(index, 1, h, seg);
            sum += query(1, index + 1, h, 1, h, seg);
        }
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }

    private static int query(int nodenum, int left, int right, int nodeleft, int noderight, int[] seg) {
        if (nodeleft > right || left > noderight) return 0;
        else if (left <= nodeleft && noderight <= right) return seg[nodenum];
        int mid = (nodeleft + noderight) / 2;
        return query(nodenum * 2, left, right, nodeleft, mid, seg) + query(nodenum * 2 + 1, left, right, mid + 1, noderight, seg);
    }

    private static void update(int index, int value, int h, int[] seg) {
        index += h - 1;
        seg[index] += value;
        while (index > 1) {
            index /= 2;
            seg[index] = seg[index * 2] + seg[index * 2 + 1];
        }
    }

}