import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken()), tc = 1;
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) {
                bw.write("Case #" + tc + ": INSOMNIA\n");
                tc++;
            } else {
                boolean[] check = new boolean[10];
                int cnt = 1, num = 0;
                while (true) {
                    int temp = n * cnt;
                    String s = String.valueOf(temp);
                    for (int i = 0; i < s.length(); i++) {
                        check[s.charAt(i) - '0'] = true;
                    }

                    if (all(check)) {
                        num = temp;
                        break;
                    }
                    cnt++;
                }
                bw.write("Case #" + tc + ": " + num + "\n");
                tc++;
            }
        }
        bw.flush();
        bw.close();
    }

    private static boolean all(boolean[] check) {
        for (int i = 0; i < 10; i++) {
            if (!check[i]) return false;
        }
        return true;
    }
}