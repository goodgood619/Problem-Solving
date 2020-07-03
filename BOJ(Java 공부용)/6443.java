import java.io.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};
    static boolean ok = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s = br.readLine();
            int[] alpha = new int[26];
            for (int i = 0; i < s.length(); i++) {
                alpha[s.charAt(i) - 'a']++;
            }
            StringBuilder sb = new StringBuilder();
            make(alpha, 0, s.length(), sb);
        }
        bw.flush();
        bw.close();
    }

    private static void make(int[] alpha, int cnt, int depth, StringBuilder sb) throws IOException {
        if (cnt == depth) {
            for (int i = 0; i < sb.length(); i++) {
                bw.write(sb.charAt(i));
            }
            bw.write("\n");
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (alpha[i] > 0) {
                alpha[i]--;
                sb.append((char) (i + 'a'));
                make(alpha, cnt + 1, depth, sb);
                sb.deleteCharAt(sb.length() - 1);
                alpha[i]++;
            }
        }
    }
}