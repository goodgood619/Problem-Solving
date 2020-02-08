import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
        }
        dp[0] = -987654;
        int en = 0;
        for (int i = 0; i < n; i++) {
            int idx = lowerbound(1, en + 1, arr[i], dp);
            dp[idx] = arr[i];
            if (idx == en + 1) en++;
        }
        System.out.println(n - en);
    }

    private static class p {
        int index, port;

        private p(int index, int port) {
            this.index = index;
            this.port = port;
        }
    }

    private static int lowerbound(int left, int right, int num, int[] arr) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < num) left = mid + 1;
            else right = mid;
        }
        return right;
    }
}