import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BigInteger a = new BigInteger(st.nextToken()), b = new BigInteger(st.nextToken());
        if (a.compareTo(BigInteger.ZERO) < 0 && b.compareTo(BigInteger.ZERO) > 0) {
            BigInteger c = a.divide(b), d = a.remainder(b);
            c = c.subtract(BigInteger.ONE);
            d = d.add(b);
            bw.write(c + "\n" + d);
        } else if (a.compareTo(BigInteger.ZERO) < 0 && b.compareTo(BigInteger.ZERO) < 0) {
            BigInteger c = a.divide(b), d = a.remainder(b);
            c = c.add(BigInteger.ONE);
            d = d.subtract(b);
            bw.write(c + "\n" + d);
        } else {
            BigInteger c = a.divide(b), d = a.remainder(b);
            bw.write(c + "\n" + d);
        }
        bw.flush();
        bw.close();
    }
}