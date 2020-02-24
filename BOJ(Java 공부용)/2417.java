import java.io.*;
import java.math.BigInteger;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger n = new BigInteger(br.readLine());
        BigInteger left = BigInteger.valueOf(1), right = n, ans = BigInteger.ZERO,divide = BigInteger.valueOf(2);
        while (left.compareTo(right) <= 0) {
            BigInteger mid = left.add(right).divide(divide);
            BigInteger temp = mid;
            mid = mid.multiply(mid);
            if (mid.compareTo(n) >= 0) {
                ans = temp;
                right = temp.subtract(BigInteger.valueOf(1));
            } else left = temp.add(BigInteger.valueOf(1));
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }
}