import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String s = br.readLine();
            int cnt = s.length() + 1;
            int n = Integer.parseInt(s);
            if (n == 0) break;
            while (n != 0) {
                int p = n % 10;
                if (p == 1) cnt += 2;
                else if (p == 0) cnt += 4;
                else cnt += 3;
                n /= 10;
            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }
}