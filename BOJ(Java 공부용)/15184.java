import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') cnt[s.charAt(i) - 'A']++;
            if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') cnt[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            System.out.print((char) (i + 65) + " | ");
            while (cnt[i] != 0) {
                System.out.print('*');
                cnt[i]--;
            }
            System.out.println();
        }
    }
}