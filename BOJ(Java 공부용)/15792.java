import java.io.*;
import java.math.BigDecimal;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        bw.write(new BigDecimal(input[0]).divide(new BigDecimal(input[1]),1001,BigDecimal.ROUND_HALF_UP)+"\n");
        bw.flush();
        bw.close();
    }
}