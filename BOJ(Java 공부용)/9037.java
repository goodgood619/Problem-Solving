import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                if (arr[i] % 2 == 1) arr[i]++;
            }
            int cnt = 0;
            while (true) {
                int same = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == arr[(i + 1) % arr.length]) same++;
                }
                if (same == n) {
                    break;
                }
                int[] temp = new int[n];

                for (int i = 0; i < temp.length; i++) {
                    temp[i] = arr[i] / 2;
                    arr[i] /= 2;
                }
                for (int i = 0; i < arr.length; i++) {
                    arr[(i + 1) % arr.length] += temp[i];
                }
                for (int i = 0; i < arr.length; i++) {
                    if (arr[i] % 2 == 1) arr[i]++;
                }
                cnt++;

            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }
}