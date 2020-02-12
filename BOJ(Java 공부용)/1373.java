import java.io.*;
import java.math.BigInteger;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        BigInteger sum = new BigInteger(s, 2);
        bw.write(sum.toString(8));
        bw.flush();
        bw.close();

    }
}