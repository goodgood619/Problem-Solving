import java.io.*;
import java.math.BigInteger;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger n = new BigInteger(br.readLine(), 10);
        bw.write(n.toString(9) + "\n");
        bw.flush();
        bw.close();
    }
}