import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        m *= k;
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (m <= 0) break;
            m -= arr[i];
            cnt++;
        }
        if (m > 0 && cnt == n) bw.write("STRESS");
        else bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }
}