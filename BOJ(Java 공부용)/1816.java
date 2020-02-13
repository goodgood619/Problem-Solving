import java.io.*;
import static java.lang.StrictMath.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[1000001];
        notprime[0] = true;
        notprime[1] = true;
        int cnt = 2;
        for (int i = 2; i <= sqrt(1000000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 1000000; j += i) {
                if (notprime[j]) continue;
                notprime[j] = true;
                cnt++;
            }
        }
        int[] arr = new int[1000001 - cnt];
        int idx = 0;
        for (int i = 2; i < 1000000; i++) {
            if (!notprime[i]) arr[idx++] = i;
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            Long num = Long.parseLong(br.readLine());
            boolean check = false;
            for (int i = 0; i < arr.length; i++) {
                if (num % arr[i] == 0) {
                    check = true;
                    break;
                }
            }
            bw.write(check ? "NO\n" : "YES\n");
        }
        bw.flush();
        bw.close();

    }
}