import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            int[] arr = new int[n];
            int[] arr2 = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);
            int idx = 0;
            for (int i = 0, j = n - 1; i <= j; i++, j--) {
                arr2[i] = arr[idx++];
                if (idx < arr.length) arr2[j] = arr[idx++];
            }
            int max = 0;
            for (int i = 0; i < arr2.length; i++) {
                max = max(max, abs(arr2[i] - arr2[(i + 1) % arr2.length]));
            }

            bw.write(max + "\n");
        }
        bw.flush();
        bw.close();
    }

}