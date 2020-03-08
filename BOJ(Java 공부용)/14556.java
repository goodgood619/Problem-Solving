import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long ans = 1;
        for (int i = 1; i <= 2 * n - 1; i += 2) {
            ans *= i;
            ans %= 1000000009;
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }
}