import java.io.*;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[100001];
        for (int i = 0; i <= 100000; i++) arr[i] = go(i);

        while (true) {
            String s = br.readLine();
            if (s.equals("END")) break;
            int n = Integer.parseInt(s);
            int nsum = go(n), max = 0;
            for (int i = n; i >= 0; i--) {
                int tsum = arr[i];
                if (tsum < nsum) {
                    max = max(max, i);
                    break;
                }
            }
            bw.write(max + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int go(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
}