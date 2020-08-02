import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sum = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int value = Integer.parseInt(st.nextToken());
            sum += value;
            list.add(value);
        }
        int totalSum = sum;
        sum /= 3;
        if (totalSum % 3 != 0) {
            bw.write("NO");
        } else {
            for (int value : list) {
                sum -= (value / 2);
            }
            bw.write((sum > 0) ? "NO" : "YES");
        }
        bw.flush();
        bw.close();
    }
}