import java.io.*;
import java.util.*;

import static java.lang.Long.max;
import static java.lang.Long.min;
import static java.lang.Math.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";
        while ((s = br.readLine()) != null) {
            s = s.trim();
            long x = Long.parseLong(s);
            int n = Integer.parseInt(br.readLine()), same = 0;
            long[] rego = new long[n + 1];
            boolean check = false;
            long ans1 = 0, ans2 = 0, diff = (long) -1e9, gob = 10000000;
            x *= gob;

            for (int i = 1; i <= n; i++) {
                rego[i] = Long.parseLong(br.readLine());
                if (rego[i] == x / 2) {
                    same++;
                }
            }
            Arrays.sort(rego);
            for (int i = 1; i <= n; i++) {
                long piece = rego[i];
                for (long j = gob; j <= x; j += gob) {
                    int idx = lowerbound(1, n + 1, x - piece, rego);
                    if (idx >= rego.length) continue;
                    if (rego[idx] == piece && same == 1) continue;
                    if (rego[idx] + piece == x) {
                        check = true;
                        if (diff < abs(rego[idx] - piece)) {
                            diff = abs(rego[idx] - piece);
                            ans1 = min(rego[idx], piece);
                            ans2 = max(rego[idx], piece);
                        }
                    }
                }
            }
            if (check) bw.write("yes " + ans1 + " " + ans2 + "\n");
            else bw.write("danger\n");
        }
        bw.flush();
        bw.close();

    }

    private static int lowerbound(int left, int right, long value, long[] arr) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < value) left = mid + 1;
            else right = mid;
        }
        return right;
    }
}