import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = 1;
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            if (n % 2 == 1) {
                String[] s = new String[n];
                for (int i = 0; i < n; i++) {
                    s[i] = br.readLine();
                }
                bw.write("SET " + t + "\n");
                for (int i = 0; i < n; i += 2) {
                    bw.write(s[i] + "\n");
                }
                for (int i = n - 2; i >= 0; i -= 2) {
                    bw.write(s[i] + "\n");
                }
                t++;
            } else {
                String[] s = new String[n];
                for (int i = 0; i < n; i++) {
                    s[i] = br.readLine();
                }
                bw.write("SET " + t + "\n");
                for (int i = 0; i < n; i += 2) {
                    bw.write(s[i] + "\n");
                }
                for (int i = n - 1; i >= 0; i -= 2) {
                    bw.write(s[i] + "\n");
                }
                t++;
            }
        }
        bw.flush();
        bw.close();
    }
}