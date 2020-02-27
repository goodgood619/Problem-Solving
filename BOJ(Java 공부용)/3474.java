import java.io.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int sum2 = 0, sum5 = 0;
            for (int i = 2; i <= n; i *= 2) sum2 += (n / i);
            for (int i = 5; i <= n; i *= 5) sum5 += (n / i);
            bw.write(min(sum2, sum5) + "\n");
        }
        bw.flush();
        bw.close();
    }
}