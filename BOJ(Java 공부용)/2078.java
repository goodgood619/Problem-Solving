import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int left = 0, right = 0;
        while (n != 1 || m != 1) {
            if (n < m) {
                m -= n;
                right++;
            } else if (n > m) {
                n -= m;
                left++;
            }

            if (n == 1 && m != 1) {
                right += (m - 1);
                m = 1;
            }
            if (n != 1 && m == 1) {
                left += (n - 1);
                n = 1;
            }
        }
        bw.write(left + " " + right + "");
        bw.flush();
        bw.close();
    }
}