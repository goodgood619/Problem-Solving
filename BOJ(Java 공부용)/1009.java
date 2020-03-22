import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            int ans = go(a, b, 10);
            ans %= 10;
            if (ans == 0) bw.write("10\n");
            else bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int go(int a, int b, int mod) {
        if (b == 0) return 1;
        else if (b == 1) return a;
        else if (b % 2 == 1) {
            int temp = go(a, (b - 1) / 2, mod);
            return temp * temp * a % mod;
        } else {
            int temp = go(a, b / 2, mod);
            return temp * temp % mod;
        }
    }
}