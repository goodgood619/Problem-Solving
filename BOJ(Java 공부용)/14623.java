import java.io.*;
import java.math.BigInteger;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger a = new BigInteger(br.readLine(), 2);
        BigInteger b = new BigInteger(br.readLine(), 2);
        a = a.multiply(b);
        bw.write(a.toString(2));
        bw.flush();
        bw.close();
    }
}