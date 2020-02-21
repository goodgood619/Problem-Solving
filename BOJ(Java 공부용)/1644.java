import java.io.*;
import static java.lang.StrictMath.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[4000001];
        int cnt = 0;
        for (int i = 2; i <= sqrt(4000000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 4000000; j += i) {
                if (notprime[j]) continue;
                notprime[j] = true;
                cnt++;
            }
        }
        int[] prime = new int[3999999 - cnt];
        int idx = 0;
        for (int i = 2; i < 4000000; i++) {
            if (!notprime[i]) prime[idx++] = i;
        }

        int n = Integer.parseInt(br.readLine());

        int left = 0, right = 0, sum = 0, ans = 0;
        while (left <= right) {
            if (prime[left] > n) break;
            if (sum < n) {
                if (right == prime.length) break;
                sum += prime[right];
                right++;
            } else {
                if (sum == n) {
                    ans++;
                }
                sum -= prime[left];
                left++;
            }
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }
}