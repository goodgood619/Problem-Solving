import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int cur = arr[0], cnt = 1;
        for (int i = 1; i < n; i++) {
            if (cur < arr[i]) {
                cur = arr[i];
                cnt++;
            }
        }
        bw.write(cnt + "\n");
        cur = arr[n - 1];
        cnt = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > cur) {
                cnt++;
                cur = arr[i];
            }
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }
}