import java.io.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 3; i++) {
            String s = br.readLine();
            int cnt = 1;
            int ans = 1;
            for (int j = 1; j < s.length(); j++) {
                if (s.charAt(j) == s.charAt(j - 1)) {
                    cnt++;
                } else {
                    ans = max(ans, cnt);
                    cnt = 1;
                }
            }
            ans = max(ans, cnt);
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }
}