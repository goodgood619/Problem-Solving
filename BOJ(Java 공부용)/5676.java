import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        while ((s = br.readLine()) != null) {
            s = s.trim();
            String[] input = s.split(" ");
            int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]);
            StringTokenizer st = new StringTokenizer(br.readLine());
            int h = 1;
            while (h < n) h <<= 1;
            int[] seg = new int[h * 2];
            for (int i = 1; i <= n; i++) {
                int num = Integer.parseInt(st.nextToken());
                update(i, num, h, seg);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                String c = st.nextToken();
                if (c.equals("C")) {
                    int index = Integer.parseInt(st.nextToken()), value = Integer.parseInt(st.nextToken());
                    update(index, value, h, seg);
                } else {
                    int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
                    int ans = query(1, left, right, 1, h, seg);
                    if (ans == 1) sb.append('+');
                    else if (ans == 0) sb.append('0');
                    else sb.append('-');
                }
            }
            bw.write(sb.toString()+"\n");
        }
        bw.flush();
        bw.close();
    }

    private static void update(int index, int value, int h, int[] seg) {
        index += h - 1;
        if (value > 0) seg[index] = 1;
        else if (value == 0) seg[index] = 0;
        else seg[index] = -1;
        while (index > 1) {
            index /= 2;
            seg[index] = seg[index * 2] * seg[index * 2 + 1];
        }
    }

    private static int query(int nodenum, int left, int right, int nodeleft, int noderight, int[] seg) {
        if (left > noderight || nodeleft > right) return 1;
        else if (left <= nodeleft && noderight <= right) return seg[nodenum];
        int mid = (nodeleft + noderight) / 2;
        return query(nodenum * 2, left, right, nodeleft, mid, seg) * query(nodenum * 2 + 1, left, right, mid + 1, noderight, seg);
    }
}