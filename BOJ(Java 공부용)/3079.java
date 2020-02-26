import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        long left = 0, right = (long) 1e18, ans = 0;
        while (left <= right) {
            long mid = (left + right) / 2, cnt = 0;
            for (int i = 0; i < arr.length; i++) {
                cnt += (mid / arr[i]);
            }
            if (cnt < m) left = mid + 1;
            else {
                ans = mid;
                right = mid - 1;
            }
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }
}