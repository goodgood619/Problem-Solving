import java.io.*;

import static java.lang.StrictMath.pow;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int mod = 1;
            int cnt = (int) pow(10, mod);
            while (n > cnt) {
                int res = n % cnt;
                if (res >= 5 * cnt / 10) {
                    n += (cnt - res);
                } else {
                    n -= res;
                }
                mod++;
                cnt = (int) pow(10, mod);
            }
            bw.write(n + "\n");
        }
        bw.flush();
        bw.close();
    }
}