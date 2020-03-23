import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken()), p = Long.parseLong(st.nextToken());
        long ans = 1;
        for (long i = n; i >= 1; i--) {
            ans = ans * i;
            ans %= p;
        }
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }
}