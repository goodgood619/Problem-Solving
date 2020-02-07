import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    //    static int[] gox = {0, 1, -1, 0};
    //    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x1 = Integer.parseInt(st.nextToken()), y1 = Integer.parseInt(st.nextToken()), x2 = Integer.parseInt(st.nextToken()), y2 = Integer.parseInt(st.nextToken());
        int x3 = Integer.parseInt(st.nextToken()), y3 = Integer.parseInt(st.nextToken()), x4 = Integer.parseInt(st.nextToken()), y4 = Integer.parseInt(st.nextToken());
        int ccw1 = ccw(new p(x1, y1), new p(x2, y2), new p(x3, y3));
        int ccw2 = ccw(new p(x1, y1), new p(x2, y2), new p(x4, y4));
        int ccw3 = ccw(new p(x3, y3), new p(x4, y4), new p(x1, y1));
        int ccw4 = ccw(new p(x3, y3), new p(x4, y4), new p(x2, y2));
        long ans = (long) ccw1 * ccw2;
        long ans2 = (long) ccw3 * ccw4;
        System.out.println(ans < 0 && ans2 < 0 ? 1 : 0);
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