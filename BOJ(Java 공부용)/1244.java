import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(br.readLine());
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int student = Integer.parseInt(st.nextToken()), pos = Integer.parseInt(st.nextToken());
            if (student == 1) {
                for (int j = pos; j <= n; j += pos) {
                    if (arr[j] == 0) {
                        arr[j] = 1;
                    } else arr[j] = 0;
                }
            } else {
                int start = 0, end = 0;
                for (int j = pos, left = pos - 1, right = pos + 1; left >= 1 && right <= n; left--, right++) {
                    if (arr[left] == arr[right]) {
                        start = left;
                        end = right;
                    } else break;
                }
                if (start == 0) {
                    if (arr[pos] == 0) arr[pos] = 1;
                    else arr[pos] = 0;
                } else {
                    for (int j = start; j <= end; j++) {
                        if (arr[j] == 0) arr[j] = 1;
                        else arr[j] = 0;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            bw.write(arr[i] + " ");
            if (i % 20 == 0) bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}