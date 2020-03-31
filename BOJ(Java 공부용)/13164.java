import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        int[] diff = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n - 1; i++) diff[i] = arr[i + 1] - arr[i];
        Arrays.sort(diff);
        long sum = 0;
        for (int i = 0; i<diff.length-(k-1)  ;i++) {
            sum += diff[i];
        }
        bw.write(sum + "");
        bw.flush();
        bw.close();
    }
}