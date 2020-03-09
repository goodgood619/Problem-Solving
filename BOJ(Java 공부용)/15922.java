import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static long ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        p[] arr = new p[n];
        for (int i = 0; i < n; i++) arr[i] = new p(0, 0);
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i].x = Integer.parseInt(st.nextToken());
            arr[i].y = Integer.parseInt(st.nextToken());
        }

        int sx = arr[0].x, sy = arr[0].y;
        long sum = sy - sx;
        for (int i = 1; i < n; i++) {
            int nx = arr[i].x, ny = arr[i].y;
            if (sx == nx) {
                if (sy < ny) {
                    sum += (ny - sy);
                    sy = ny;
                }
            } else {
                if (sy < ny && nx <= sy) {
                    sum += (ny - sy);
                    sy = ny;
                } else if (sy < ny && nx > sy) {
                    sum += (ny - nx);
                    sy = ny;
                }
            }
        }
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}