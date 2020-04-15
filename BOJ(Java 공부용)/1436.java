import java.io.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int num = 666, cnt = 1;
        while (true) {
            if (cnt == n) break;
            num++;
            int temp = num;
            int six = 0;
            while (temp > 0) {
                int sk = temp % 10;
                if (sk == 6) six++;
                else if (six < 3) six = 0;
                temp /= 10;
            }
            if (six >= 3) cnt++;
        }
        bw.write(num + "");
        bw.flush();
        bw.close();
    }
}