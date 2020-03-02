import java.io.*;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if ((j - i + 1) % 2 == 1) continue;
                ans = max(ans, go(i, j, s));
            }
        }
        if (ans == 0) bw.write("0\n");
        else bw.write(ans + " ");
        bw.flush();
        bw.close();
    }

    private static int go(int st, int en, String s) {
        int sum1 = 0, sum2 = 0;
        for (int i = st, j = en; i <= (st + en) / 2; i++, j--) {
            sum1 += s.charAt(i) - '0';
            sum2 += s.charAt(j) - '0';
        }
        if (sum1 == sum2) return en - st + 1;
        else return 0;
    }
}