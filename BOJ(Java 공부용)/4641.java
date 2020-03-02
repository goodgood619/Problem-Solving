import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<Integer> v = new ArrayList<>();
            boolean check = false;
            for (int i = 0; ; i++) {
                int num = Integer.parseInt(st.nextToken());
                if (num == 0) break;
                if (num == -1) {
                    check = true;
                    break;
                }
                v.add(num);
            }
            if (check) break;
            int cnt = 0;
            for (int i = 0; i < v.size(); i++) {
                for (int j = 0; j < v.size(); j++) {
                    if (i == j || v.get(i) != 2 * v.get(j)) continue;
                    cnt++;
                    break;
                }
            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }
}