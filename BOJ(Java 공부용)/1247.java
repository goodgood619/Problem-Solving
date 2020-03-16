import java.io.*;
import java.math.BigInteger;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 3; i++) {
            int n = Integer.parseInt(br.readLine());
            BigInteger sum = BigInteger.ZERO;
            for (int j = 0; j < n; j++) {
                BigInteger num = new BigInteger(br.readLine());
                sum = sum.add(num);
            }
            if (sum.compareTo(BigInteger.ZERO) > 0) bw.write("+\n");
            else if (sum.compareTo(BigInteger.ZERO) < 0) bw.write("-\n");
            else if (sum.compareTo(BigInteger.ZERO) == 0) bw.write("0\n");
        }
        bw.flush();
        bw.close();
    }
}