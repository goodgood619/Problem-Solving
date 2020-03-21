import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) break;
            long ans = 1;
            if (n == m || m == 0) {
                bw.write("1\n");
                continue;
            }
            if (m > n - m) {
                m = n - m;
            }
            for (int i = 1; i <= m; i++) {
                ans = ans * (n - m + i) / i;
            }
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }
}