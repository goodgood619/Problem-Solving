import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken()), b = Long.parseLong(st.nextToken()), c = Long.parseLong(st.nextToken());
        System.out.println(go(a, b, c));
    }

    private static long go(long a, long b, long c) {
        if (b == 0) return 1;
        if (b % 2 == 0) {
            return go(a * a % c, b / 2, c) % c;
        } else {
            return a * go(a * a % c, (b - 1) / 2, c) % c;
        }
    }
}