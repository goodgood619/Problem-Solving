import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int divide = s / k, mod = s % k;
        long[] arr = new long[k];
        for (int i = 0; i < k; i++) {
            arr[i] = divide;
        }
        if (mod == 0) {
            long gob = 1;
            for (int i = 0; i < k; i++) {
                gob *= arr[i];
            }
            System.out.println(gob);
        } else {
            long gob = 1;
            for (int i = 0; i < mod; i++) {
                arr[i]++;
            }
            for (int i = 0; i < k; i++) {
                gob *= arr[i];
            }
            System.out.println(gob);
        }
    }
}