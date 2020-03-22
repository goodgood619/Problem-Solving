import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int h = 1;
        while (h < n) h <<= 1;
        int[] seg = new int[h * 2];
        Arrays.fill(seg, (int) 1e9);
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            update(i, Integer.parseInt(st.nextToken()), h, seg);
        }
        int q = Integer.parseInt(br.readLine());
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int what = Integer.parseInt(st.nextToken());
            if (what == 1) {
                int index = Integer.parseInt(st.nextToken()), value = Integer.parseInt(st.nextToken());
                update(index, value, h, seg);
            } else {
                int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
                bw.write(go(1, left, right, 1, h, seg) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }

    private static int go(int nodenum, int left, int right, int nodeleft, int noderight, int[] seg) {
        if (left > noderight || nodeleft > right) return (int) 1e9;
        else if (left <= nodeleft && noderight <= right) return seg[nodenum];
        int mid = (nodeleft + noderight) / 2;
        return min(go(nodenum * 2, left, right, nodeleft, mid, seg), go(nodenum * 2 + 1, left, right, mid + 1, noderight, seg));
    }

    private static void update(int index, int num, int h, int[] seg) {
        index += h - 1;
        seg[index] = num;
        while (index > 1) {
            index /= 2;
            seg[index] = min(seg[index * 2], seg[index * 2 + 1]);
        }
    }
}