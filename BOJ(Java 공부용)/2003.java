import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), cnt = 0;
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        int left = 0, right = 0, sum = 0;
        while (left <= right) {
            if (sum < m) {
                if (right == n) break;
                sum += arr[right];
                right++;
            } else {
                if (sum == m) {
                    cnt++;
                }
                sum -= arr[left++];
            }
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }
}