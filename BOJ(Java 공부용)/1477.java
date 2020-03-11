import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n + 2];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        arr[n] = 0;
        arr[n + 1] = l;
        Arrays.sort(arr);
        int left = 0, right = l, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2, cnt = 0;
            for (int i = 1; i < arr.length; i++) {
                cnt += (arr[i] - arr[i - 1] - 1) / mid;
            }
            if (cnt <= m) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }
}