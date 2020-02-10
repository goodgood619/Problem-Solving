import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        go(n, b, sb);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }

    private static void go(int num, int mod, StringBuilder sb) {
        if (num < mod) {
            if (num < 10) sb.append(num);
            else sb.append((char) (num + 55));
            return;
        }
        go(num / mod, mod, sb);
        go(num % mod, mod, sb);
    }
}