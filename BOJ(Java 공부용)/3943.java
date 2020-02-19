import java.io.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int max = n;
            while (n != 1) {
                int p = n;
                if (p % 2 == 0) {
                    p /= 2;
                } else p = p * 3 + 1;
                max = max(max, p);
                n = p;
            }
            bw.write(max + "\n");
        }
        bw.flush();
        bw.close();
    }
}