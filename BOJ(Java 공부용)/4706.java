import java.io.*;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String[] input = br.readLine().split(" ");
            double a= Double.parseDouble(input[0]);
            double b = Double.parseDouble(input[1]);
            if(a ==0 && b==0) break;
           System.out.printf(String.format("%.3f\n",sqrt(1-pow(b/a,2.0))));

        }
    }
}