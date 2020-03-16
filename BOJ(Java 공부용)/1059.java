import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int l = Integer.parseInt(br.readLine());
        int[] arr = new int[l];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < l; i++) arr[i] = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(br.readLine());
        Arrays.sort(arr);
        int idx = lowerbound(0, l - 1, n, arr);
        if (arr[idx] == n) System.out.println(0);
        else if (idx == 0) System.out.println((n * (arr[0] - n)) - 1);
        else System.out.println((n - arr[idx - 1]) * (arr[idx] - n) - 1);
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