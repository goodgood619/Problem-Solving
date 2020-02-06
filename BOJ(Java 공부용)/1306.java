import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int h = 1;
        while (h < n) h <<= 1;
        int[] seg = new int[h * 2];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            update(i, Integer.parseInt(st.nextToken()), seg, h);
        }
        for (int i = m; i <= n - m + 1; i++) {
            bw.write(query(1, i - m + 1, i + m - 1, 1, h, seg) + " ");
        }
        bw.flush();
        bw.close();
    }

    private static void update(int index, int value, int[] seg, int h) {
        index += h - 1;
        seg[index] = value;
        while (index > 1) {
            index /= 2;
            seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
        }
    }

    private static int query(int nodenum, int left, int right, int nodeleft, int noderight, int[] seg) {
        if (nodeleft > right || left > noderight) return 0;
        else if (left <= nodeleft && noderight <= right) return seg[nodenum];
        int mid = (nodeleft + noderight) / 2;
        return max(query(nodenum * 2, left, right, nodeleft, mid, seg), query(nodenum * 2 + 1, left, right, mid + 1, noderight, seg));
    }
}