import java.io.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        go(0, arr, n);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void go(int index, int[] arr, int n) {
        if (index == n) {
            ans++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            arr[index] = i;
            if (check(arr, index)) {
                go(index + 1, arr, n);
            } else arr[index] = 0;
        }
    }

    private static boolean check(int[] arr, int index) {
        for (int i = 0; i < index; i++) {
            if (arr[i] == arr[index] || Math.abs(i - index) == Math.abs(arr[i] - arr[index])) return false;
        }
        return true;
    }
}