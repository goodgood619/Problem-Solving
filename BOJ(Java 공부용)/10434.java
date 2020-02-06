import java.io.*;
import java.util.*;

import static java.lang.Math.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        boolean[] notprime = new boolean[10001];
        for (int i = 2; i <= sqrt(10000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 10000; j += i) {
                notprime[j] = true;
            }
        }
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int tc = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
            HashMap<Integer, Integer> m = new HashMap<>();
            boolean check = false;
            if (n == 1) {
                bw.write(tc + " " + n + " NO\n");
                continue;
            }
            int temp = n;
            while (true) {
                int sum = 0;
                while (temp > 0) {
                    sum += (temp % 10) * (temp % 10);
                    temp /= 10;
                }
                if (sum == 1) {
                    check = true;
                    break;
                }
                if (m.get(sum) == null) {
                    m.put(sum, 1);
                } else if (m.get(sum) != null) {
                    break;
                }
                temp = sum;
            }
            if (!notprime[n] && check) bw.write(tc + " " + n + " YES\n");
            else bw.write(tc + " " + n + " NO\n");
        }
        bw.flush();
        bw.close();
    }
}