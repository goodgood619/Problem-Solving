import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
            ans = (int) 1e9;
            go(start, end, 0);
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static void go(int start, int end, int cnt) {
        if (start > end) return;
        if (start == end) {
            ans = min(ans, cnt);
            return;
        }
        go(start * 2, end + 3, cnt + 1);
        go(start + 1, end, cnt + 1);
    }
}