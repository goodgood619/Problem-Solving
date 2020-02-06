import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Math.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[1000001];
        notprime[1] = true;
        for (int i = 2; i <= sqrt(1000000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 1000000; j += i) {
                notprime[j] = true;
            }
        }
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) break;
            for (int i = n - 1; i >= 1; i--) {
                if (!notprime[i] && !notprime[n - i]) {
                    bw.write(n + " = " + (n - i) + " + " + i + "\n");
                    break;
                }
            }
        }
        bw.flush();
        bw.close();
    }
}