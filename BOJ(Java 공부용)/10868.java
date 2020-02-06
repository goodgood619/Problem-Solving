import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int h = 1;
        while (h < n) h <<= 1;
        int[] seg = new int[h * 2];
        Arrays.fill(seg, (int) 2e9);
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            update(i, Integer.parseInt(st.nextToken()), h, seg);
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
            bw.write(query(1, left, right, 1, h, seg) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int query(int nodenum, int left, int right, int nodeleft, int noderight, int[] seg) {
        if (left > noderight || nodeleft > right) return (int) 2e9;
        else if (left <= nodeleft && noderight <= right) return seg[nodenum];
        int mid = (nodeleft + noderight) / 2;
        return min(query(nodenum * 2, left, right, nodeleft, mid, seg), query(nodenum * 2 + 1, left, right, mid + 1, noderight, seg));
    }

    private static void update(int index, int value, int h, int[] seg) {
        index += h - 1;
        seg[index] = min(seg[index], value);
        while (index > 1) {
            index /= 2;
            seg[index] = min(seg[index * 2], seg[index * 2 + 1]);
        }
    }
}