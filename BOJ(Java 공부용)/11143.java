import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            int h = 1;
            while (h < n) h <<= 1;
            int[] seg = new int[2 * h];
            for (int i = 0; i < a + b; i++) {
                st = new StringTokenizer(br.readLine());
                String what = st.nextToken();
                if (what.equals("P")) {
                    int num = Integer.parseInt(st.nextToken()), value = Integer.parseInt(st.nextToken());
                    update(seg, h, num, value);
                } else {
                    int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
                    bw.write(query(1, left, right, 1, h, seg) + "\n");
                }
            }
        }
        bw.flush();
        bw.close();
    }

    private static int query(int nodenum, int left, int right, int nodeleft, int noderight, int[] seg) {
        if (left > noderight || nodeleft > right) return 0;
        else if (left <= nodeleft && noderight <= right) return seg[nodenum];
        int mid = (nodeleft + noderight) / 2;
        return query(nodenum * 2, left, right, nodeleft, mid, seg) + query(nodenum * 2 + 1, left, right, mid + 1, noderight, seg);
    }

    private static void update(int[] seg, int h, int index, int value) {
        index += h - 1;
        seg[index] += value;
        while (index > 1) {
            index /= 2;
            seg[index] = seg[index * 2] + seg[index * 2 + 1];
        }
    }
}