import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
        int res = gcd(x, y);
        bw.write(res * (x / res + y / res - 1) + "");
        bw.flush();
        bw.close();
    }

    private static int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b % a, a);
    }
}