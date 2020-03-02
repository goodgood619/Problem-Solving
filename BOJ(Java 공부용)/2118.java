import java.io.*;

import static java.lang.Integer.max;
import static java.lang.Integer.min;
import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        p[] arr = new p[n];
        int[] sum = new int[n * 2];
        int[] temp = new int[n * 2];
        for (int i = 0; i < n; i++) {
            arr[i] = new p(i, (i + 1) % n, Integer.parseInt(br.readLine()));
            temp[i] = arr[i].dist;
        }
        for (int i = n; i < 2 * n; i++) {
            temp[i] = temp[i - n];
        }

        for (int i = 0; i < 2 * n; i++) {
            if (i == 0) sum[i] = temp[i];
            else {
                sum[i] += sum[i - 1] + temp[i];
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i - 1 < 0) {
                    max = max(max, min(sum[j - 1], sum[n - 1] - sum[j - 1]));
                } else max = max(max, min(abs(sum[j - 1] - sum[i - 1]), abs(sum[n + i - 1] - sum[j - 1])));
            }
        }
        bw.write(max + " ");
        bw.flush();
        bw.close();
    }

    private static class p {
        int here, next, dist;

        private p(int here, int next, int dist) {
            this.here = here;
            this.next = next;
            this.dist = dist;
        }
    }
}