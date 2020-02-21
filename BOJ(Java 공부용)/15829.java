import java.io.*;
import java.math.BigInteger;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        BigInteger a = BigInteger.ZERO;
        String s = br.readLine();
        for (int i = 0; i < s.length(); i++) {
            int num = s.charAt(i) - 'a' + 1;
            BigInteger b = BigInteger.valueOf(31);
            b = b.pow(i);
            b = b.multiply(BigInteger.valueOf(num));
            a = a.add(b);
            a = a.remainder(BigInteger.valueOf(1234567891));
        }
        System.out.println(a);
    }
}