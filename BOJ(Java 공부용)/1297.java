import java.io.*;
import java.util.StringTokenizer;
import static java.lang.StrictMath.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        double d = Double.parseDouble(st.nextToken()), x = Double.parseDouble(st.nextToken()), y = Double.parseDouble(st.nextToken());
        double temp = sqrt(d * d / (x * x + y * y));
        System.out.println((int) (x * temp) + " " + (int) (y * temp));
    }
}