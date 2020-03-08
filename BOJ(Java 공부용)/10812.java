import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = i;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken()), mid = Integer.parseInt(st.nextToken());
            int[] temp = new int[n + 1];
            for (int j = 1; j <= n; j++) temp[j] = arr[j];
            int idx = left;
            for (int j = mid; j <= right; j++) {
                arr[idx++] = temp[j];
            }
            for (int j = left; j < mid; j++) {
                arr[idx++] = temp[j];
            }
        }
        for (int i = 1; i <= n; i++) bw.write(arr[i] + " ");
        bw.flush();
        bw.close();
    }
}