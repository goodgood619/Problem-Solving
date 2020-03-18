import java.io.*;
import java.util.ArrayList;
import java.util.List;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[1000001];
        for (int i = 2; i <= sqrt(1000000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 1000000; j += i) {
                notprime[j] = true;
            }
        }
        int n = Integer.parseInt(br.readLine());
        if (n < 8) {
            System.out.println(-1);
            return;
        }
        List<Integer> v = new ArrayList<>();
        v.add(2);
        if (n % 2 == 0) {
            v.add(2);
            n -= 4;
        } else {
            v.add(3);
            n -= 5;
        }

        for (int i = 2; i <= 1000000; i++) {
            if (notprime[i]) continue;
            if (!notprime[n - i] && n > i) {
                v.add(n - i);
                v.add(i);
                break;
            }
        }

        if (v.size() != 4) bw.write("-1");
        else {
            for (Integer a : v) {
                bw.write(a + " ");
            }
        }
        bw.flush();
        bw.close();
    }
}