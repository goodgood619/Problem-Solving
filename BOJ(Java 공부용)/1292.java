import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
        left--;
        right--;
        int[] arr = new int[1000];
        int num = 1;
        for (int i = 0; i < 1000; ) {
            int idx = 0;
            for (int j = i; j < i + num && j < 1000; j++) {
                arr[j] = num;
                idx = j;
            }
            num++;
            i = idx + 1;
        }
        int sum = 0;
        for (int i = left; i <= right; i++) sum += arr[i];
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }
}