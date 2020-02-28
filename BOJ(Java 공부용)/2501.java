import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (i == n / i) v.add(i);
                else {
                    v.add(i);
                    v.add(n / i);
                }
            }
        }
        Collections.sort(v);
        if (v.size() < k) System.out.println(0);
        else {
            for (int i = 0; i < v.size(); i++) {
                if (k == 1) {
                    System.out.println(v.get(i));
                    return;
                }
                k--;
            }
        }
    }
}