import java.io.*;
import java.math.BigInteger;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";
        while ((s = br.readLine()) != null) {
            BigInteger mod = new BigInteger(s);
            BigInteger a = new BigInteger(String.valueOf(BigInteger.ONE));
            for (int i = 1; ; i++) {
                if (a.remainder(mod).equals(BigInteger.ZERO)) {
                    bw.write(i + "\n");
                    break;
                }
                a = a.multiply(BigInteger.TEN);
                a = a.add(BigInteger.ONE);
            }
        }
        bw.flush();
        bw.close();
    }

}