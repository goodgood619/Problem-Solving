import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            StringBuilder low = new StringBuilder();
            int[] arr = new int[n * 2];
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                low.append(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            StringBuilder high = new StringBuilder();
            for (int i = 0; i < m; i++) {
                high.append(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
            for (int i = n, j = 0; i < 2 * n; i++, j++) arr[i] = arr[j];

            for (int i = 0; i < n; i++) {
                StringBuilder cur = new StringBuilder();
                for (int j = i; j < i + m; j++) {
                    cur.append(arr[j]);
                }
                long down = Long.parseLong(low.toString());
                long up = Long.parseLong(high.toString());
                long temp = Long.parseLong(cur.toString());
                if (down <= temp && temp <= up) cnt++;
            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }
}