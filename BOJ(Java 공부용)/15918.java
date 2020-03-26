import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
        boolean[] check = new boolean[n + 1];
        int[] number = new int[2 * n + 1];
        number[x] = y - x - 1;
        number[y] = y - x - 1;
        check[y - x - 1] = true;
        go(1, check, number, n);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void go(int here, boolean[] check, int[] number, int n) {
        if (here == 2 * n + 1) {
            ans++;
            return;
        }
        if (number[here] > 0) {
            go(here + 1, check, number, n);
        }
        for (int i = 1; i <= n; i++) {
            if (!check[i] && here + i + 1 <= 2 * n && number[here] == 0 && number[here + i + 1] == 0) {
                number[here + i + 1] = i;
                number[here] = i;
                check[i] = true;
                go(here + 1, check, number, n);
                check[i] = false;
                number[here + i + 1] = 0;
                number[here] = 0;
            }
        }
    }
}
