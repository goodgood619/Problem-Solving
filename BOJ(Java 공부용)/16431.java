import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int bx = -1, by = -1, dx = -1, dy = -1, ex = -1, ey = -1;
        for (int i = 0; i < 3; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            if (i == 0) {
                bx = Integer.parseInt(st.nextToken());
                by = Integer.parseInt(st.nextToken());
            }
            if (i == 1) {
                dx = Integer.parseInt(st.nextToken());
                dy = Integer.parseInt(st.nextToken());
            }
            if (i == 2) {
                ex = Integer.parseInt(st.nextToken());
                ey = Integer.parseInt(st.nextToken());
            }
        }

        int d = abs(dx - ex) + abs(dy - ey);
        int b = max(abs(bx - ex), abs(by - ey));
        if (b < d) bw.write("bessie");
        else if (b > d) bw.write("daisy");
        else bw.write("tie");
        bw.flush();
        bw.close();
    }
}