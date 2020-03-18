import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            if (n == 1) {
                bw.write("0\n");
                continue;
            }
            int ret = 1;
            for (int i = 2; i < n; i++) {
                int temp = n;
                while (temp % i == 0) {
                    ret++;
                    temp /= i;
                }
            }
            bw.write(ret + "\n");
        }
        bw.flush();
        bw.close();
    }
}