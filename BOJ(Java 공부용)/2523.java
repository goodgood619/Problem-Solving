import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int cnt = 1;
        int cnt2 = n - 1;
        for (int i = 1; i <= 2 * n - 1; i++){
            if (cnt <= n) {
                for (int j = 1; j <= i; j++) {
                    bw.write("*");
                }
                bw.write("\n");
            }
            else {
                for (int j = 1; j <= cnt2; j++) {
                    bw.write("*");
                }
                bw.write("\n");
                cnt2--;
            }
            cnt++;
        }
        bw.flush();
        bw.close();
    }
}