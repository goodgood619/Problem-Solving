import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            double sum = 0;
            double[] arr = new double[num];
            for (int j = 0; j < num; j++) {
                arr[j] = Double.parseDouble(st.nextToken());
                sum += arr[j];

            }
            sum /= num;
            int cnt = 0;
            for (int j = 0; j < num; j++) {
                if (sum < arr[j]) cnt++;
            }
            System.out.print(String.format("%.3f", (double) cnt * 100 / num) + "%");
            System.out.println();
        }
    }
}