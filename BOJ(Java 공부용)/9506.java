import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == -1) break;
            ArrayList<Integer> v = new ArrayList<>();
            for (int i = 1; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    int second = n / i;
                    if (i == second) {
                        v.add(i);
                    } else {
                        if (second == n) {
                            v.add(i);
                            continue;
                        }
                        v.add(i);
                        v.add(second);
                    }
                }
            }
            Collections.sort(v);
            int sum = 0;
            for (int i = 0; i < v.size(); i++) sum += v.get(i);
            if (sum == n) {
                bw.write(n + " =");
                for (int i = 0; i < v.size(); i++) {
                    if (i == v.size() - 1) {
                        bw.write(" " + v.get(i) + "\n");
                        continue;
                    }
                    bw.write(" " + v.get(i));
                    bw.write(" +");
                }
            } else bw.write(n + " is NOT perfect.\n");
        }
        bw.flush();
        bw.close();
    }
}