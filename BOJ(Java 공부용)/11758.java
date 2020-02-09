import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        p[] arr = new p[3];
        for (int i = 0; i < 3; i++) arr[i] = new p(0, 0);
        for (int i = 0; i < 3; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken()), y1 = Integer.parseInt(st.nextToken());
            arr[i].x = x1;
            arr[i].y = y1;
        }
        int ret = ccw(arr[0], arr[1], arr[2]);
        if (ret > 0) bw.write("1");
        else if (ret < 0) bw.write("-1");
        else bw.write("0");
        bw.flush();
        bw.close();
    }

    private static int ccw(p a, p b, p c) {
        return (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}