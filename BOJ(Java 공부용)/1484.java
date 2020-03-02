import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int g = Integer.parseInt(br.readLine());
        List<Integer> v = new ArrayList<>();
        for (int i = 1; i <= sqrt(g); i++) {
            if (g % i == 0) {
                if (i == g / i) {
                    v.add(i);
                } else {
                    v.add(i);
                    v.add(g / i);
                }
            }
        }

        Collections.sort(v);
        List<Integer> ans = new ArrayList<>();
        for (int i = 0, j = v.size() - 1; i <= j; i++, j--) {
            //a+b -> x, a-b -> y
            int x = v.get(j), y = v.get(i);
            double a = (x + y) / 2.0;
            double b = (x - y) / 2.0;
            if (a != (int) a || b != (int) b || b <= 0) continue;
            ans.add((int) a);
        }
        if (ans.size() == 0) System.out.println(-1);
        else {
            Collections.sort(ans);
            for (int i = 0; i < ans.size(); i++) bw.write(ans.get(i) + "\n");
            bw.flush();
            bw.close();
        }
    }
}