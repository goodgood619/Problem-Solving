import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long a = Long.parseLong(br.readLine());
        long x = Long.parseLong(br.readLine());
        long mod = 1000000007;
        a %= mod;
        bw.write(go(a, x, mod) + "");
        bw.flush();
        bw.close();
    }

    private static long go(long a, long x, long mod) {
        if (x == 0) return 1;
        else if (x == 1) return a;
        else if (x % 2 == 1) {
            long temp = go(a, (x - 1) / 2, mod);
            temp *= temp;
            temp %= mod;
            temp *= a;
            temp %= mod;
            return temp;
        } else {
            long temp = go(a, x / 2, mod);
            return (temp % mod * temp % mod) % mod;
        }
    }
}