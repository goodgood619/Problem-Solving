import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] cnt = new int[53];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) cnt[Integer.parseInt(st.nextToken())]++;
        String s = br.readLine();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ' ') cnt[0]--;
            else if (c >= 'A' && c <= 'Z') {
                cnt[c - 'A' + 1]--;
            } else if (c >= 'a' && c <= 'z') {
                cnt[c - 'a' + 27]--;
            }
        }
        for (int i = 0; i < 53; i++) {
            if (cnt[i] != 0) {
                System.out.println('n');
                return;
            }
        }
        System.out.println('y');
    }
}