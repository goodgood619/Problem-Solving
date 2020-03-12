import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[] fact = new long[1000001];
        long p = 1000000007;
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i <= 1000000; i++) {
            fact[i] = fact[i - 1] * i % p;
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        long a = fact[n], b = fact[n - k] * fact[k] % p;
        long temp = go(b, p - 2, p);
        long ans = (a % p) * (temp % p) % p;
        bw.write(ans + "\n");
        bw.flush();
        bw.close();
    }

    private static long go(long b, long p, long mod) {
        if (p == 0) return 1;
        if (p == 1) return b;
        else if (p % 2 == 0) {
            long temp = go(b, p / 2, mod);
            return (temp % mod * temp % mod) % mod;
        } else {
            long temp = go(b, (p - 1) / 2, mod);
            return (temp % mod * temp % mod) * b % mod;
        }
    }
}