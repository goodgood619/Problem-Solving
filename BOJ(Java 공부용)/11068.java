import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            boolean check = false;
            for (int i = 2; i < 65; i++) {
                ArrayList<Integer> v = new ArrayList<>();
                int temp = n;
                go(temp, i, v);
                boolean no = false;
                for (int j = 0, k = v.size() - 1; j <= k; j++, k--) {
                    if (v.get(j) != v.get(k)) {
                        no = true;
                        break;
                    }
                }
                if (!no) {
                    check = true;
                    bw.write("1\n");
                    break;
                }
            }
            if (!check) bw.write("0\n");
        }
        bw.flush();
        bw.close();
    }

    private static void go(int num, int mod, ArrayList<Integer> v) {
        if (num < mod) {
            v.add(num);
            return;
        }
        go(num / mod, mod, v);
        go(num % mod, mod, v);
    }
}