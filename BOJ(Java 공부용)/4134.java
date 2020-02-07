import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[70001];
        for (int i = 2; i <= sqrt(70000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 70000; j += i) {
                notprime[j] = true;
            }
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            long n = Long.parseLong(st.nextToken());
            if (n <= 1) {
                bw.write("2\n");
                continue;
            }
            for (long i = n; ; i++) {
                boolean no = false;
                long m = (long) sqrt(i);
                for (int j = 2; j <= m; j++) {
                    if (notprime[j]) continue;
                    if (i % (long) j == 0) {
                        no = true;
                        break;
                    }
                }
                if (!no) {
                    bw.write(i + "\n");
                    break;
                }
            }
        }
        bw.flush();
        bw.close();
    }
}