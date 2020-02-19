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
        int m = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int left = 0, right = n - 1, cnt = 0;
        while (left < right) {
            if (arr[left] + arr[right] == m) {
                cnt++;
                right--;
            } else if (arr[left] + arr[right] < m) {
                left++;
            } else if (arr[left] + arr[right] > m) {
                right--;
            }
        }
        bw.write(cnt + "\n");
        bw.flush();
        bw.close();
    }
}