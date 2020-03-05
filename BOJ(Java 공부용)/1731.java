import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1, 1, 1, -1, -1};
    static int[] goy = {1, -1, 0, 0, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] arr = new long[n];
        long[] diff = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }
        for (int i = 1; i < n; i++) {
            diff[i - 1] = arr[i] - arr[i - 1];
        }
        if (diff[0] == diff[1]) {
            System.out.println(arr[n - 1] + diff[0]);
        } else {
            System.out.println(arr[n - 1] * diff[1] / diff[0]);
        }

    }
}