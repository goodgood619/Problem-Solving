import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        Map<String, Integer> map = new HashMap<>();
        map.put("TTT", 1);
        map.put("TTH", 2);
        map.put("THT", 3);
        map.put("THH", 4);
        map.put("HTT", 5);
        map.put("HTH", 6);
        map.put("HHT", 7);
        map.put("HHH", 8);
        while (t-- > 0) {
            int[] cnt = new int[9];
            String s = br.readLine();
            for (int i = 0; i < s.length() - 2; i++) {
                String temp = s.substring(i, i + 3);
                cnt[map.get(temp)]++;
            }
            for (int i = 1; i <= 8; i++) bw.write(cnt[i] + " ");
            bw.write("\n");
        }
        bw.flush();
        bw.close();

    }
}