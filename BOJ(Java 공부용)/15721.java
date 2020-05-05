import java.io.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(br.readLine()), t = Integer.parseInt(br.readLine()), choice = Integer.parseInt(br.readLine());
        int cur = 0, idx = -1, n = 1, burn = 0, dagie = 0;

        while (true) {
            if (cur == 0) burn++;
            else if (cur == 1) dagie++;
            else if (cur == 2) burn++;
            else if (cur == 3) dagie++;
            else if (cur == 4) {
                for (int i = 0; i <= n; i++) {
                    burn++;
                    idx = (idx + 1) % a;
                    if (choice == 0 && burn == t) {
                        System.out.println(idx);
                        System.exit(0);
                    }
                }
                cur++;
                continue;
            } else {
                for (int i = 0; i <= n; i++) {
                    dagie++;
                    idx = (idx + 1) % a;
                    if (choice == 1 && dagie == t) {
                        System.out.println(idx);
                        System.exit(0);
                    }
                }
                n++;
                cur = 0;
                continue;
            }
            idx = (idx + 1) % a;
            cur++;
            if (choice == 1 && dagie == t) break;
            if (choice == 0 && burn == t) break;
        }
        bw.write(idx + "");
        bw.flush();
        bw.close();
    }
}