import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) arr[i] = Double.parseDouble(br.readLine());
        Arrays.sort(arr);
        double one = 0, two = 0;
        int cnt = 0;
        for (int i = k, j = n - k; i < j; i++) {
            one += arr[i];
            cnt++;
        }
        one /= cnt;
        double left = arr[k], right = arr[n - k - 1];
        for (int i = k - 1, j = n - k; i >= 0; i--, j++) {
            arr[i] = left;
            arr[j] = right;
        }
        for (int i = 0; i < n; i++) {
            two += arr[i];
        }
        two /= n;
        System.out.println(String.format("%.2f", one));
        System.out.println(String.format("%.2f", two));
    }
}