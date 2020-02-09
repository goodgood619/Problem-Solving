import java.io.*;
import java.util.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[] arr = new int[m];
        for (int i = 0; i < m; i++) {
            int num = Integer.parseInt(br.readLine());
            arr[i] = num;
        }
        int ans = 0, price = 0;
        Arrays.sort(arr);
        for (int i = 0; i < m; i++) {
            int total = arr[i] * min(n, m - i);
            if (ans < total) {
                ans = total;
                price = arr[i];
            }
        }
        System.out.println(price + " " + ans);
    }
}