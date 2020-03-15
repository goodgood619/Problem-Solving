import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int counter = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int h = 1;
        while (h <= 1000000) h <<= 1;
        int[] seg = new int[h * 2];
        int k = Integer.parseInt(st.nextToken());
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int what = Integer.parseInt(st.nextToken());
            if (what == 2) {
                int idx = Integer.parseInt(st.nextToken()), value = Integer.parseInt(st.nextToken());
                update(idx, value, h, seg);
            } else {
                int taste = Integer.parseInt(st.nextToken());
                int ans = query(1, taste, seg, 1, h, h);
                update(ans, -1, h, seg);
                bw.write(ans + "\n");
            }
        }
        bw.flush();
        bw.close();
    }

    private static int query(int nodenum, int taste, int[] seg, int nodeleft, int noderight, int h) {
        if (nodeleft == noderight) {
            return nodenum - h + 1;
        }
        int leftcnt = seg[nodenum * 2], mid = (nodeleft + noderight) / 2;
        if (leftcnt >= taste) {
            return query(nodenum * 2, taste, seg, nodeleft, mid, h);
        } else {
            return query(nodenum * 2 + 1, taste - leftcnt, seg, mid + 1, noderight, h);
        }
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