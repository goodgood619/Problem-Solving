import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken());
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < l; i++) {
            String s = br.readLine();
            if (map.get(s) == null) {
                map.put(s, i);
            } else {
                map.remove(s);
                map.put(s, i);
            }
        }
        List<p> v = new ArrayList<>();
        for (String s : map.keySet()) {
            int value = map.get(s);
            v.add(new p(s, value));
        }
        v.sort((a, b) -> {
            if (a.idx < b.idx) return -1;
            else if (a.idx > b.idx) return 1;
            else return 0;
        });
        for (int i = 0; i < v.size(); i++) {
            bw.write(v.get(i).name + "\n");
            k--;
            if (k == 0) break;
        }
        bw.flush();
        bw.close();
    }

    private static class p {
        String name;
        int idx;

        private p(String name, int idx) {
            this.name = name;
            this.idx = idx;
        }
    }
}