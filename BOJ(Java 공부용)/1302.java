import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> map = new HashMap<>();
        List<p> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            if (map.get(s) == null) {
                map.put(s, 1);
            } else {
                int value = map.get(s);
                value++;
                map.remove(s);
                map.put(s, value);
            }
        }

        for (String s : map.keySet()) {
            v.add(new p(map.get(s), s));
        }
        v.sort((a, b) -> {
            if (a.cnt > b.cnt) return -1;
            else if (a.cnt < b.cnt) return 1;
            else {
                return a.s.compareTo(b.s);
            }
        });
        bw.write(v.get(0).s + " ");
        bw.flush();
        bw.close();
    }

    private static class p {
        int cnt;
        String s;

        private p(int cnt, String s) {
            this.cnt = cnt;
            this.s = s;
        }
    }
}