import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) arr[i] = Long.parseLong(st.nextToken());
        long cluster = Long.parseLong(br.readLine()), total = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;
            if (arr[i] < cluster) total += cluster;
            else {
                if (arr[i] % cluster == 0) total += cluster * arr[i] / cluster;
                else total = total + cluster * (arr[i] / cluster + 1);
            }
        }
        System.out.println(total);
    }
}