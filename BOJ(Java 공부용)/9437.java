import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static BigInteger ans = new BigInteger("2").pow(500);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) break;
            int p = Integer.parseInt(st.nextToken());
            List<List<Integer>> v = new ArrayList<>();
            for (int i = 1, j = n; i < j; i += 2, j -= 2) {
                List<Integer> temp = new ArrayList<>();
                temp.add(i);
                temp.add(i + 1);
                temp.add(j);
                temp.add(j - 1);
                Collections.sort(temp);
                v.add(temp);
            }
            for (int i = 0; i < v.size(); i++) {
                int idx = -1;
                for (int j = 0; j < v.get(i).size(); j++) {
                    if (p == v.get(i).get(j)) {
                        idx = i;
                        break;
                    }
                }
                if (idx != -1) {
                    for (int j = 0; j < v.get(idx).size(); j++) {
                        if (p == v.get(i).get(j)) continue;
                        bw.write(v.get(idx).get(j) + " ");
                    }
                    bw.write("\n");
                    break;
                }
            }
        }
        bw.flush();
        bw.close();
    }
}