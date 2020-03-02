import java.io.*;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int l = Integer.parseInt(br.readLine()), a = Integer.parseInt(br.readLine()), b = Integer.parseInt(br.readLine()), c = Integer.parseInt(br.readLine()), d = Integer.parseInt(br.readLine());
        int mok1 = a / c, mok2 = b / d;
        if (a % c != 0) {
            mok1++;
        }
        if (b % d != 0) {
            mok2++;
        }
        if (l - max(mok1, mok2) >= 0) System.out.println(l - max(mok1, mok2));
        else System.out.println(0);
    }
}