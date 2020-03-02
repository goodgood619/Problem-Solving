import java.io.*;
import java.util.StringTokenizer;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            int res = go(num);
            if (res < num) bw.write("Deficient\n");
            else if (res == num) bw.write("Perfect\n");
            else bw.write("Abundant\n");
        }
        bw.flush();
        bw.close();
    }

    private static int go(int num) {
        int sum = 0;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                int second = num / i;
                if (i == second) {
                    sum += i;
                } else {
                    sum += i;
                    sum += second;
                }
            }
        }
        sum -= num;
        return sum;
    }
}