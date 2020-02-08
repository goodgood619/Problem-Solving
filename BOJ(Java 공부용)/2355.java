import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken()), m = Long.parseLong(st.nextToken());
        if (n > m) {
            long temp = n;
            n = m;
            m = temp;
        }
        long right = m * (m + 1) / 2, left = n * (n - 1) / 2;
        System.out.println(right - left);
    }
}