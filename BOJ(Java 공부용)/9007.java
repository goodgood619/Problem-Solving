import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
            int[][] arr = new int[4][n];
            int[] a = new int[n * n];
            int[] b = new int[n * n];
            for (int i = 0; i < 4; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            int idx = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[idx] = arr[0][i] + arr[1][j];
                    b[idx++] = arr[2][i] + arr[3][j];
                }
            }

            Arrays.sort(b);
            int diff = (int) 1e9, sum = 0;
            for (int i = 0; i < a.length; i++) {
                int idx1 = lowerbound(0, b.length - 1, k - a[i], b);
                if (b[idx1] + a[i] == k) {
                    sum = k;
                    break;
                } else {
                    int temp = abs(k - b[idx1] - a[i]);
                    if (diff > temp) {
                        diff = temp;
                        sum = b[idx1] + a[i];
                    } else if (diff == temp) {
                        if (sum > b[idx1] + a[i]) sum = b[idx1] + a[i];
                    }
                    if (idx1 > 0) {
                        idx1--;
                        temp = abs(k - b[idx1] - a[i]);
                        if (diff > temp) {
                            diff = temp;
                            sum = b[idx1] + a[i];
                        } else if (diff == temp) {
                            if (sum > b[idx1] + a[i]) {
                                sum = b[idx1] + a[i];
                            }
                        }
                    }

                }
            }
            bw.write(sum + "\n");
        }
        bw.flush();
        bw.close();
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