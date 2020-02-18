import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
        int[] arr = new int[s];
        int max = 0;
        for (int i = 0; i < s; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            max = max(max, arr[i]);
        }
        long left = 0, right = max * 2, ans = 1;
        while (left <= right) {
            long mid = (left + right) / 2;
            long cnt = 0;
            for (int i = 0; i < s; i++) {
                cnt += (arr[i] / mid);
            }
            if (cnt == c) {
                ans = mid;
                left = mid + 1;
            } else if (cnt < c) {
                right = mid - 1;
            } else {
                ans = mid;
                left = mid + 1;
            }
        }

        long sum = 0, cnt = 0;
        for (int i = 0; i < s; i++) {
            cnt += (arr[i] / ans);
            if (cnt <= c) {
                sum += (arr[i] - arr[i] / ans * ans);
            } else {
                long rest = cnt - c;
                sum += rest * ans;
            }
        }
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }

}