import java.io.*;
import java.math.BigDecimal;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        String[] input2 = br.readLine().split(" ");
        bw.write(new BigDecimal(input[0]).add(new BigDecimal(input2[0]))+"\n");
        bw.write(new BigDecimal(input[0]).subtract(new BigDecimal(input2[0]))+"\n");
        bw.write(new BigDecimal(input[0]).multiply(new BigDecimal(input2[0]))+"\n");
        bw.flush();
        bw.close();
    }
}