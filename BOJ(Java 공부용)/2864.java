import java.io.*;
import java.util.StringTokenizer;

import static java.lang.StrictMath.pow;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String a = st.nextToken(), b = st.nextToken();
        StringBuilder min = new StringBuilder(), max = new StringBuilder();
        int one = 0, two = 0;
        for (int i = 0; i < a.length(); i++) {
            double pow = pow(10, a.length() - i - 1);
            if (a.charAt(i) == '6') {
                one += 5 * pow;
            } else one += (a.charAt(i) - '0') * pow;
        }
        for (int i = 0; i < b.length(); i++) {
            double pow = pow(10, b.length() - i - 1);
            if (b.charAt(i) == '6') {
                one += 5 * pow;
            } else one += (b.charAt(i) - '0') * pow;
        }

        for (int i = 0; i < a.length(); i++) {
            double pow = pow(10, a.length() - i - 1);
            if (a.charAt(i) == '5') {
                two += 6 * pow;
            } else two += (a.charAt(i) - '0') * pow;
        }
        for (int i = 0; i < b.length(); i++) {
            double pow = pow(10, b.length() - i - 1);
            if (b.charAt(i) == '5') {
                two += 6 * pow;
            } else two += (b.charAt(i) - '0') * pow;
        }
        bw.write(one + " " + two + "");
        bw.flush();
        bw.close();
    }
}