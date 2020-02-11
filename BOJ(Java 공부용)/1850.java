import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken()), m = Long.parseLong(st.nextToken());
        long r = gcd(n, m);
        for (long i = 1; i <= r; i++) bw.write("1");
        bw.flush();
        bw.close();
    }

    private static long gcd(long n, long m) {
        if (n % m == 0) return m;
        return gcd(m % n, n);
    }
}