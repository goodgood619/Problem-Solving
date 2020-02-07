import java.io.*;
import java.util.StringTokenizer;
import java.util.TreeMap;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        TreeMap<Integer, Integer> map = new TreeMap<>();
        map.put(0, -1);
        map.put(300001, -1);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            map.put(num, -1);
            int lower = map.lowerKey(num);
            int higher = map.higherKey(num);
            int value = max(map.get(lower), map.get(higher)) + 1;
            map.put(num, value);
            ans += value;
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }
}