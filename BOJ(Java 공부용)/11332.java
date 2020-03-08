import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            // n*t <=l*1억
            int n = Integer.parseInt(st.nextToken());
            BigInteger cnt = new BigInteger(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            l *= 100000000;
            BigInteger timeout = new BigInteger(String.valueOf(l));
            if (s.equals("O(N)")) {
                if (cnt.multiply(new BigInteger(String.valueOf(n))).compareTo(timeout) <= 0) {
                    bw.write("May Pass.\n");
                } else bw.write("TLE!\n");
            } else if (s.equals("O(2^N)")) {
                BigInteger temp = new BigInteger(String.valueOf(2));
                if (temp.pow(n).multiply(cnt).compareTo(timeout) <= 0) bw.write("May Pass.\n");
                else bw.write("TLE!\n");
            } else if (s.equals("O(N^2)")) {
                BigInteger temp = new BigInteger(String.valueOf(n));
                if (temp.pow(2).multiply(cnt).compareTo(timeout) <= 0) bw.write("May Pass.\n");
                else bw.write("TLE!\n");
            } else if (s.equals("O(N^3)")) {
                BigInteger temp = new BigInteger(String.valueOf(n));
                if (temp.pow(3).multiply(cnt).compareTo(timeout) <= 0) bw.write("May Pass.\n");
                else bw.write("TLE!\n");
            } else {
                BigInteger temp = new BigInteger(String.valueOf(cnt));
                boolean no = false;
                while (n > 0) {
                    temp = temp.multiply(new BigInteger(String.valueOf(n)));
                    n--;
                    if (temp.compareTo(timeout) > 0) {
                        no = true;
                        break;
                    }
                }
                if (no) bw.write("TLE!\n");
                else bw.write("May Pass.\n");
            }
        }
        bw.flush();
        bw.close();
    }
}