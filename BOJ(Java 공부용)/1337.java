import java.io.*;
import java.util.Arrays;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; i + j < n && j < 5; j++) {
                if (arr[i + j] < arr[i] + 5) cnt++;
            }
            ans = max(cnt, ans);
        }
        bw.write((5 - ans) + "\n");
        bw.flush();
        bw.close();
    }
}