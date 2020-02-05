import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = n - 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i;j++)
                bw.write(" ");
            for (int k = 1; k <= 2 * q + 1;k++)
                bw.write("*");
            q--;
            bw.write("\n");
        }
        int r = 1;
        for (int j = n-1; j>0; j--) {

            for (int k = j - 1; k > 0;k--)
                bw.write(" ");
            for (int p = 1; p <= 2 * r + 1;p++)
                bw.write("*");
            bw.write("\n");
            r++;
        }
        bw.flush();
        bw.close();
    }
}