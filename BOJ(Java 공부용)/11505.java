import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    //    static int[] gox = {0, 1, -1, 0};
    //    static int[] goy = {1, 0, 0, -1};
    static long mod = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int h = 1;
        while (h < n) h <<= 1;
        long[] seg = new long[h * 2];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            long value = Long.parseLong(st.nextToken());
            update(i, value, h, seg);
        }
        for (int i = 0; i < m + k; i++) {
            st = new StringTokenizer(br.readLine());
            int choice = Integer.parseInt(st.nextToken());
            if (choice == 1) {
                int b = Integer.parseInt(st.nextToken());
                long c = Long.parseLong(st.nextToken());
                update(b, c, h, seg);
            } else {
                int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
                bw.write(query(1, left, right, 1, h, seg) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }

    private static long query(int nodenum, int left, int right, int nodeleft, int noderight, long[] seg) {
        if (left > noderight || nodeleft > right) return 1;
        else if (left <= nodeleft && noderight <= right) return seg[nodenum];
        int mid = (nodeleft + noderight) / 2;
        return (query(nodenum * 2, left, right, nodeleft, mid, seg) * query(nodenum * 2 + 1, left, right, mid + 1, noderight, seg)) % mod;
    }

    private static void update(int index, long value, int h, long[] seg) {
        index += h - 1;
        seg[index] = value;
        while (index > 1) {
            index /= 2;
            seg[index] = (seg[index * 2] * seg[index * 2 + 1]) % mod;
        }
    }
}