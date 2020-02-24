import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<p> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken()), strike = Integer.parseInt(st.nextToken()), ball = Integer.parseInt(st.nextToken());
            v.add(new p(num, strike, ball));
        }
        int cnt = 0;
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 123; i <= 987; i++) {
            if (go(i, v)) {
                ans.add(i);
                cnt++;
            }
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }

    private static boolean go(int num, ArrayList<p> v) {
        int[] count = new int[10];
        int p = num, max = 0;
        while (p != 0) {
            count[p % 10]++;
            max = max(max, count[p % 10]);
            p /= 10;
        }
        if (max >= 2 || count[0] >= 1) return false;
        for (int i = 0; i < v.size(); i++) {
            int num2 = v.get(i).num, strike = v.get(i).strike, ball = v.get(i).ball;
            String s = String.valueOf(num), s2 = String.valueOf(num2);
            boolean[] check = new boolean[10];
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == s2.charAt(j)) {
                    check[s.charAt(j) - '0'] = true;
                    strike--;
                }
            }
            if (strike != 0) return false;
            for (int j = 0; j < s.length(); j++) {
                if (!check[s.charAt(j) - '0']) {
                    int num3 = s.charAt(j) - '0';
                    for (int k = 0; k < s2.length(); k++) {
                        if (num3 == s2.charAt(k) - '0') {
                            check[s2.charAt(k) - '0'] = true;
                            ball--;
                        }
                    }
                }
            }
            if (ball != 0) return false;
        }

        return true;
    }

    private static class p {
        int num, strike, ball;

        private p(int num, int strike, int ball) {
            this.num = num;
            this.strike = strike;
            this.ball = ball;
        }
    }
}