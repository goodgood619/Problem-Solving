import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            boolean[] check = new boolean[26];
            boolean no = false;
            for (int j = 0; j < s.length(); j++) {
                if (!check[s.charAt(j) - 'a']) {
                    check[s.charAt(j) - 'a'] = true;
                } else {
                    if (s.charAt(j) == s.charAt(j - 1)) continue;
                    else {
                        no = true;
                        break;
                    }
                }
            }
            if (!no) ans++;
        }
        System.out.println(ans);
    }
}