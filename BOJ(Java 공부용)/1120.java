import java.io.*;
import java.util.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String s1 = st.nextToken(), s2 = st.nextToken();
        int min = (int) 1e9;
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            int cnt = 0;
            for (int j = 0; j < s1.length(); j++) {
                if (s1.charAt(j) == s2.charAt(i + j)) continue;
                else cnt++;
            }
            min = min(min, cnt);
        }
        System.out.println(min);
    }
}