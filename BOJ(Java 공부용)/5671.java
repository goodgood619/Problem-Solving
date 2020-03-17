import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";
        while ((s = br.readLine()) != null) {
            String[] input = s.split(" ");
            int a = Integer.parseInt(input[0]), b = Integer.parseInt(input[1]), ans = 0;
            for (int i = a; i <= b; i++) {
                int[] cnt = new int[10];
                int p = i;
                while (p > 0) {
                    cnt[p % 10]++;
                    p /= 10;
                }
                boolean check = false;
                for (int j = 0; j < 10; j++) {
                    if (cnt[j] >= 2) {
                        check = true;
                        break;
                    }
                }
                if (!check) ans++;
            }
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }
}