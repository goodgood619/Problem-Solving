import java.io.*;
import java.math.BigInteger;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        bw.write(new BigInteger(input[0]).add(new BigInteger(input[1]))+"\n");
        bw.flush();
        bw.close();
    }
}
