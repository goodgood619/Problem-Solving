import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 0) bw.write("0");
        else {
            List<Integer> v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                v.add(Integer.parseInt(br.readLine()));
            }
            Collections.sort(v);
            double num = n * 0.15;
            if (num - (int) num >= 0.5) {
                num = (int) num + 1;
            }
            int num2 = (int) num, sum = 0, cnt = 0;
            for (int i = num2; i < v.size() - num2; i++) {
                sum += v.get(i);
                cnt++;
            }
            double check = sum / (cnt * 1.0);
            int ans = 0;
            if (check - (int) check >= 0.5) {
                ans = (int) check + 1;
            } else if (check - (int) check < 0.5) {
                ans = (int) check;
            }
            bw.write(ans + "");
        }
        bw.flush();
        bw.close();
    }
}