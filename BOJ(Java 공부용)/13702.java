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
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            max = max(max, arr[i]);
        }
        int left = 1, right = max, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2, cnt = 0;
            for (int i = 0; i < arr.length; i++) {
                cnt += (arr[i] / mid);
            }
            if (cnt >= m) {
                ans = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        System.out.println(ans);
    }
}