import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            if (a == 0 && b == 0) break;
            HashSet<Integer> one = new HashSet<>();
            HashSet<Integer> two = new HashSet<>();
            int p = 2;
            while (a != 1) {
                if (a % p == 0) {
                    one.add(p);
                    a /= p;
                } else p++;
            }
            p = 2;
            while (b != 1) {
                if (b % p == 0) {
                    two.add(p);
                    b /= p;
                } else p++;
            }

            int sum1 = 0, max1 = 0, sum2 = 0, max2 = 0;
            for (Integer integer : one) {
                sum1 += integer;
                max1 = max(max1, integer);
            }
            for (Integer integer : two) {
                sum2 += integer;
                max2 = max(max2, integer);
            }

            sum1 -= max1;
            sum2 -= max2;
            System.out.println(max1 - sum1 > max2 - sum2 ? "a" : "b");
        }
    }
}