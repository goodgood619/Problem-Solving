import java.io.*;
import java.util.ArrayList;

import static java.lang.Integer.max;
import static java.lang.Integer.min;
import static java.lang.StrictMath.abs;
import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[10001];
        notprime[1] = true;
        notprime[0] = true;
        for (int i = 2; i <= sqrt(10000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 10000; j += i) notprime[j] = true;
        }
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 2; i < 10000; i++) {
            if (!notprime[i]) v.add(i);
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int diff = (int) 1e9, ans1 = 0, ans2 = 0;
            for (int i = 0; i < v.size(); i++) {
                int a = v.get(i);
                int idx = lowerbound(0, v.size(), n - a, v);
                if (idx == v.size()) continue;
                if (v.get(idx) == n - a) {
                    if (diff > abs(v.get(idx) - a)) {
                        diff = abs(v.get(idx) - a);
                        ans1 = min(v.get(idx), a);
                        ans2 = max(v.get(idx), a);
                    }
                }
            }
            bw.write(ans1 + " " + ans2 + "\n");
        }
        bw.flush();
        bw.close();

    }

    private static int lowerbound(int left, int right, int num, ArrayList<Integer> v) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (v.get(mid) < num) left = mid + 1;
            else right = mid;
        }
        return right;
    }

}