import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        List<Integer> v = new ArrayList<>();
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i == i) v.add(i);
                else {
                    v.add(n / i);
                    v.add(i);
                }
            }
        }
        Collections.sort(v);
        int cnt = 0;
        for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
            int x = v.get(i), y = v.get(j);
            double a = (x + y) / 2.0, b = (x - y) / 2.0;
            if (a >= b && a == (int) a && b == (int) b) cnt++;
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }
}