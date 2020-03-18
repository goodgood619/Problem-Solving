import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cur = 10;
        while (true) {
            if (n < cur) break;
            int mod = n % cur;
            if (mod >= cur / 2) {
                n += (cur - mod);
            } else {
                n -= mod;
            }
            cur *= 10;
        }
        bw.write(n + "");
        bw.flush();
        bw.close();
    }
}