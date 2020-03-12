import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] cnt = new int[10];
        int st = 1, point = 1;
        while (st <= n) {
            while (n % 10 != 9 && st <= n) {
                go(n, cnt, point);
                n--;
            }
            if (st > n) break;
            while (st % 10 != 0 && st <= n) {
                go(st, cnt, point);
                st++;
            }
            st /= 10;
            n /= 10;
            for (int i = 0; i < 10; i++) {
                cnt[i] += (n - st + 1) * point;
            }
            point *= 10;
        }
        for (int i = 0; i < 10; i++) bw.write(cnt[i] + " ");
        bw.flush();
        bw.close();
    }

    private static void go(int x, int[] cnt, int point) {
        while (x > 0) {
            cnt[x % 10] += point;
            x /= 10;
        }
    }
}