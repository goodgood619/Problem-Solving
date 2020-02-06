import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            HashMap<String, Integer> map = new HashMap<>();
            for (int i = 1; i <= n; i++) {
                st = new StringTokenizer(br.readLine());
                String s1 = st.nextToken();
                String s2 = st.nextToken();
                if (map.get(s2) == null) {
                    map.put(s2, 1);
                } else {
                    int value = map.get(s2);
                    value++;
                    map.remove(s2);
                    map.put(s2, value);
                }
            }
            int ans = 1;
            for (String s : map.keySet()) {
                ans *= (1 + map.get(s));
            }
            bw.write((ans - 1) + "\n");
        }
        bw.flush();
        bw.close();
    }
}