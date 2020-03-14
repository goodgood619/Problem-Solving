import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        int left = 0, right = 200000, ans = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            left = max(left, arr[i]);
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            int p = mid, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (p >= arr[i]) {
                    p -= arr[i];
                } else {
                    cnt++;
                    p = mid - arr[i];
                }
            }
            if (cnt < k) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();

    }
}