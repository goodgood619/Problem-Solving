import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import static java.lang.StrictMath.pow;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] cnt = new int[27];
        for (int i = 1; i <= n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                cnt[s.charAt(j) - 'A'] += pow(10, s.length() - j - 1);
            }
        }
        List<Integer> v = new ArrayList<>();
        for (int i = 0; i <= 26; i++) {
            v.add(cnt[i]);
        }
        Collections.sort(v);
        int sum = 0, start = 9;
        for (int i = v.size() - 1; i >= 0; i--) {
            sum += start * v.get(i);
            start--;
        }
        bw.write(sum + "");
        bw.flush();
        bw.close();
    }
}