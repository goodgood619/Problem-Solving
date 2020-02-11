import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<Integer> arr = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) arr.add(Integer.parseInt(st.nextToken()));
            HashSet<ArrayList<Integer>> set = new HashSet<>();
            boolean ok = false;
            set.add(arr);
            while (true) {
                ArrayList<Integer> v = new ArrayList<>();
                ArrayList<Integer> temp = new ArrayList<>();
                for (int i = 0; i < arr.size(); i++) {
                    v.add(abs(arr.get(i) - arr.get((i + 1) % arr.size())));
                }
                int zero = 0;
                for (int i = 0; i < v.size(); i++) {
                    temp.add(v.get(i));
                    if (temp.get(i) == 0) zero++;
                }
                if (zero == arr.size()) {
                    ok = true;
                    break;
                }
                if (set.contains(temp)) {
                    break;
                }
                set.add(temp);
                arr = temp;
            }
            bw.write(ok ? "ZERO\n" : "LOOP\n");
        }
        bw.flush();
        bw.close();
    }
}