import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static BigInteger ans = new BigInteger("2").pow(500);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
        List<Character> v = new ArrayList<>();
        go(m, n, v);

        for (int i = 0; i < v.size(); i++) bw.write(v.get(i));
        bw.flush();
        bw.close();
    }

    private static void go(int m, int n, List<Character> v) {
        if (m < n) {
            if (m >= 10) v.add((char) (m + 55));
            else v.add((char) (m + '0'));
            return;
        }
        go(m / n, n, v);
        go(m % n, n, v);
    }
}