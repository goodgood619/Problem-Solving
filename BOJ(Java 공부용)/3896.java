import java.io.*;
import static java.lang.StrictMath.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[1300001];
        for (int i = 2; i <= sqrt(1300000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 1300000; j += i) notprime[j] = true;
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            if (!notprime[k]) {
                bw.write("0\n");
            } else {
                int p = k;
                while (notprime[p]) {
                    p++;
                }
                int r = k;
                while (notprime[r]) {
                    r--;
                }
                bw.write((p - r) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}