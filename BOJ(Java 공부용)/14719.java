import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken()), w = Integer.parseInt(st.nextToken());
        int[] arr = new int[w];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < w; i++) arr[i] = Integer.parseInt(st.nextToken());
        int sum = 0;

        for (int i = 0; i < w; i++) {
            if (i == 0 || i == w - 1) continue;
            int leftmax = go(0, i - 1, arr, arr[i]);
            int rightmax = go(i + 1, w - 1, arr, arr[i]);
            int min = min(leftmax, rightmax);
            if (min == 0) continue;
            sum += (min - arr[i]);
        }
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }

    private static int go(int left, int right, int[] arr, int num) {
        if (left > right) return (int) 1e9;
        int max = 0;
        for (int i = left; i <= right; i++) {
            if (arr[i] >= num) {
                max = max(max, arr[i]);
            }
        }
        return max;
    }
}