import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }
        Arrays.sort(arr);
        int left = 1, right = (int) (1e9 + 5), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            long cnt = 1;
            int ptr = 0;
            for (int i = 1; i < arr.length; i++) {
                if (abs(arr[ptr] - arr[i]) >= mid) {
                    cnt++;
                    ptr = i;
                }
            }
            if (cnt >= c) {
                ans = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }
}