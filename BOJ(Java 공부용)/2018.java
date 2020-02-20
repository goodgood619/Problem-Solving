import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long left = 1, right = 1, sum = 0;
        int cnt = 0;
        while (left <= right) {
            if (left > n) break;
            if (sum < n) {
                sum += right;
                right++;
            } else {
                if (sum == n) cnt++;
                sum -= left;
                left++;
            }
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }
}