import java.io.*;
import java.math.BigInteger;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger a = new BigInteger(br.readLine());
        String s = br.readLine();
        BigInteger b= new BigInteger(br.readLine());
        if(s.equals("*")) bw.write(a.multiply(b)+"\n");
        else bw.write(a.add(b)+"\n");
        bw.flush();
        bw.close();
    }
}