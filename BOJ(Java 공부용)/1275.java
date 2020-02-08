import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int h = 1;
        while (h < n) h <<= 1;
        long[] seg = new long[h * 2];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            update(i, Integer.parseInt(st.nextToken()), h, seg);
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken()), index = Integer.parseInt(st.nextToken()), value = Integer.parseInt(st.nextToken());
            if (left > right) {
                int temp = left;
                left = right;
                right = temp;
            }
            bw.write(query(1, left, right, 1, h, seg) + "\n");
            update(index, value, h, seg);
        }
        bw.flush();
        bw.close();
    }

    private static long query(int nodenum, int left, int right, int nodeleft, int noderight, long[] seg) {
        if (left > noderight || nodeleft > right) return 0;
        else if (left <= nodeleft && noderight <= right) return seg[nodenum];
        int mid = (nodeleft + noderight) / 2;
        return query(nodenum * 2, left, right, nodeleft, mid, seg) + query(nodenum * 2 + 1, left, right, mid + 1, noderight, seg);
    }

    private static void update(int index, int value, int h, long[] seg) {
        index += h - 1;
        seg[index] = value;
        while (index > 1) {
            index /= 2;
            seg[index] = seg[index * 2] + seg[index * 2 + 1];
        }
    }
}