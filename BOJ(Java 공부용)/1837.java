import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;
import static java.lang.StrictMath.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[1000001];
        int cnt = 0;
        for (int i = 2; i <= sqrt(1000000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 1000000; j += i) {
                if (notprime[j]) continue;
                notprime[j] = true;
                cnt++;
            }
        }
        int[] arr = new int[1000001 - cnt];
        int idx = 0;
        for (int i = 2; i < 1000000; i++) {
            if (!notprime[i]) arr[idx++] = i;
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        BigInteger a = new BigInteger(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        boolean check = false;
        for (int i = 2; i < k; i++) {
            String s = String.valueOf(i);
            BigInteger b = new BigInteger(s);
            if (a.remainder(b).equals(BigInteger.ZERO)) {
                System.out.println("BAD " + i);
                check = true;
                return;
            }

        }
        System.out.println("GOOD");
    }
}