import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        p[] arr = new p[n];
        for (int i = 0; i < n; i++) arr[i] = new p(0, 0);
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; i++) {
            arr[i].port = Integer.parseInt(st.nextToken());
            arr[i].index = i;
        }
        Arrays.sort(arr, (a, b) -> {
            if (a.index < b.index) return -1;
            else if (a.index > b.index) return 1;
            else {
                if (a.port < b.port) return -1;
                else if (a.port > b.port) return 1;
                else return 0;
            }
        });
        dp[0] = -987654;
        int en = 0;
        for (int i = 0; i < n; i++) {
            int idx = lowerbound(1, en + 1, arr[i].port, dp);
            dp[idx] = arr[i].port;
            if (idx == en + 1) en++;
        }
        System.out.println(en);
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