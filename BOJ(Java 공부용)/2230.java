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
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
        int left = 0, right = 0, min = Integer.MAX_VALUE;
        while (left <= right) {
            if (right == arr.length) break;
            if (arr[right] - arr[left] < m) {
                right++;
            } else {
                min = min(min, arr[right] - arr[left]);
                left++;
            }
        }
        System.out.println(min);
    }

}