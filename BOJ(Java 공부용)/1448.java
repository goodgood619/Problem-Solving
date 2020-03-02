import java.io.*;
import java.util.Arrays;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);
        for (int i = arr.length - 1; i >= 2; i--) {
            if (arr[i] < arr[i - 1] + arr[i - 2]) {
                System.out.println(arr[i] + arr[i - 1] + arr[i - 2]);
                return;
            }
        }
        System.out.println(-1);
    }
}