import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static long ans = (long) -1e18;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> v = new ArrayList<>();
        int n = Integer.parseInt(br.readLine());
        for (int i = 3; i <= 3000; i += 3) {
            v.add(i);
        }
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                int res = n - v.get(i) - v.get(j);
                if (res > 0 && res % 3 == 0) {
                    cnt++;
                }
            }
        }
        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}