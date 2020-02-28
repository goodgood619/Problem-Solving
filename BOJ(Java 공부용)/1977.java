import java.io.*;

import static java.lang.Integer.min;
import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int sum = 0, min = (int) 1e9;
        for (int i = n; i <= m; i++) {
            if (go(i)) {
                sum += i;
                min = min(min, i);
            }
        }
        if (sum == 0) System.out.println(-1);
        else System.out.println(sum + "\n" + min);
    }

    private static boolean go(int n) {
        for (int i = 1; i <= sqrt(n); i++) {
            if (n == i * i) return true;
        }
        return false;
    }
}