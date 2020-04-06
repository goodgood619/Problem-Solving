import java.io.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int five = 0, fivecnt = 0, p = n;
        while (p > 0) {
            fivecnt += p / 5;
            p /= 5;
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int temp = i;
            while (temp % 5 == 0) temp /= 5;
            if (fivecnt > 0 && temp % 2 == 0) {
                fivecnt--;
                temp /= 2;
            }
            ans = (ans * temp) % 10;
        }
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }
}
