import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        double w = Double.parseDouble(st.nextToken()), l = Double.parseDouble(st.nextToken()), d = Double.parseDouble(st.nextToken());
        int start = 2000;
        double bronze = 0, silver = 0, gold = 0, platinum = 0, dia = 0;
        // 3,3,14면 -> 20!/(3!*3!*14!)
        BigInteger[] dp = new BigInteger[21];
        for (int i = 0; i <= 20; i++) {
            dp[i] = BigInteger.ONE;
        }
        for (int i = 2; i <= 20; i++) {
            dp[i] = dp[i].multiply(dp[i - 1]).multiply(BigInteger.valueOf(i));
        }
        for (int i = 0; i <= 20; i++) {
            for (int j = 0; j <= 20; j++) {
                for (int k = 0; k <= 20; k++) {
                    if (i + j + k == 20) {
                        p ret = go(start, i, j, k, w, l, d);
                        BigInteger cnt = dp[20].divide(dp[i]).divide(dp[j]).divide(dp[k]);
                        if (ret.score < 1500) {
                            bronze += cnt.longValue() * ret.expect;
                        }
                        if (ret.score >= 1500 && ret.score < 2000) {
                            silver += cnt.longValue() * ret.expect;
                        }
                        if (ret.score >= 2000 && ret.score < 2500) {
                            gold += cnt.longValue() * ret.expect;
                        }
                        if (ret.score >= 2500 && ret.score < 3000) {
                            platinum += cnt.longValue() * ret.expect;
                        }
                        if (ret.score >= 3000) {
                            dia += cnt.longValue() * ret.expect;
                        }
                    }
                }
            }
        }
        System.out.println(String.format("%.8f", bronze));
        System.out.println(String.format("%.8f", silver));
        System.out.println(String.format("%.8f", gold));
        System.out.println(String.format("%.8f", platinum));
        System.out.println(String.format("%.8f", dia));
    }

    private static p go(int start, int i, int j, int k, double w, double l, double d) {
        double expect = 1;
        for (int a = 1; a <= i; a++) {
            start += 50;
            expect *= w;
        }
        for (int a = 1; a <= j; a++) {
            start -= 50;
            expect *= l;
        }
        for (int a = 1; a <= k; a++) {
            expect *= d;
        }
        return new p(start, expect);
    }
}

class p {
    int score;
    double expect;

    p(int score, double expect) {
        this.score = score;
        this.expect = expect;
    }
}