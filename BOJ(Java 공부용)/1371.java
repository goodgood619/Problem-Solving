import java.io.*;
import java.util.Scanner;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";
        int[] cnt = new int[26];
        while ((s = br.readLine()) != null) {
            s = s.trim();
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == ' ' || s.charAt(i) == '\n') continue;
                cnt[s.charAt(i) - 'a']++;
            }
        }
        int max = 0;
        for (int i = 0; i < 26; i++) {
            max = max(max, cnt[i]);
        }
        for (int i = 0; i < 26; i++) {
            if (max == cnt[i]) {
                System.out.print((char) (i + 'a'));
            }
        }
    }
}