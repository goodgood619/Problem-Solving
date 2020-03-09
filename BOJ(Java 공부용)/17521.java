import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Long.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static long ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long w = Long.parseLong(st.nextToken());
        int[] bank = new int[n];
        for (int i = 0; i < n; i++) bank[i] = Integer.parseInt(br.readLine());
        ans = w;
        long rest = w / bank[0];
        go(bank, 1, n, w - rest * bank[0], rest);
        go(bank, 1, n, w, 0);
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }

    private static void go(int[] bank, int cnt, int depth, long curmoney, long coin) {
        if (cnt == depth) {
            ans = max(ans, curmoney);
            return;
        }
        if (coin > 0) {
            long buy = curmoney / bank[cnt];
            go(bank, cnt + 1, depth, curmoney - buy * bank[cnt], coin + buy);
            go(bank, cnt + 1, depth, curmoney + coin * bank[cnt], 0);
            go(bank, cnt + 1, depth, curmoney, coin);
        } else {
            long buy = curmoney / bank[cnt];
            go(bank, cnt + 1, depth, curmoney - buy * bank[cnt], coin + buy);
            go(bank, cnt + 1, depth, curmoney, coin);
        }
    }
}