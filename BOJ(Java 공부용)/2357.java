import java.io.*;
import java.util.*;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static p ans = new p(Integer.MAX_VALUE, 0);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int h = 1;
        while (h < n) h <<= 1;
        p[] seg = new p[h * 2];
        for (int i = 1; i <= 2 * h - 1; i++) seg[i] = new p(Integer.MAX_VALUE, 0);
        for (int i = 1; i <= n; i++) {
            int value = Integer.parseInt(br.readLine());
            update(i, value, h, seg);
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
            query(1, left, right, 1, h, seg);
            bw.write(ans.min + " " + ans.max + "\n");
            ans.min = Integer.MAX_VALUE;
            ans.max = 0;
        }
        bw.flush();
        bw.close();
    }

    private static void update(int index, int value, int h, p[] seg) {
        index += h - 1;
        seg[index].min = value;
        seg[index].max = value;
        while (index > 1) {
            index /= 2;
            seg[index].min = min(seg[index * 2].min, seg[index * 2 + 1].min);
            seg[index].max = max(seg[index * 2].max, seg[index * 2 + 1].max);
        }
    }

    private static void query(int nodenum, int left, int right, int nodeleft, int noderight, p[] seg) {
        if (left > noderight || nodeleft > right) return;
        else if (left <= nodeleft && noderight <= right) {
            ans.min = min(ans.min, seg[nodenum].min);
            ans.max = max(ans.max, seg[nodenum].max);
            return;
        }
        int mid = (nodeleft + noderight) / 2;
        query(nodenum * 2, left, right, nodeleft, mid, seg);
        query(nodenum * 2 + 1, left, right, mid + 1, noderight, seg);
    }

    private static class p {
        int min, max;

        private p(int min, int max) {
            this.min = min;
            this.max = max;
        }
    }
}