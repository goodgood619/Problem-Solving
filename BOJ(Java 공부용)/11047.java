import java.io.*;
import java.util.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        List<Integer> coin = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            coin.add(Integer.parseInt(br.readLine()));
        }
        int cnt = 0;
        for (int i = coin.size() - 1; i >= 0; i--) {
            if (k == 0) break;
            if (k < coin.get(i)) continue;
            int rest = k / coin.get(i);
            k = k - rest * coin.get(i);
            cnt += rest;
        }
        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}