import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(br.readLine());
        int sum = -1, idx = -1;
        for (int i = 1; i <= n; i++) {
            int ret = go(i, arr, n);
            if (sum < ret) {
                sum = ret;
                idx = i;
            }
        }
        bw.write(idx + "");
        bw.flush();
        bw.close();
    }

    private static int go(int st, int[] arr, int n) {
        int[] check = new int[n + 1];
        int cnt = 0;
        while (check[st] == 0) {
            check[st] = 1;
            st = arr[st];
            cnt++;
        }
        return cnt;
    }
}