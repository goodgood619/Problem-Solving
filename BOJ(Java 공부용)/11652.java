import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        TreeMap<Long, Integer> m = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            long num = Long.parseLong(br.readLine());
            if (m.get(num) == null) {
                m.put(num, 1);
            } else {
                int value = m.get(num);
                value++;
                m.remove(num);
                m.put(num, value);
            }
        }

        Iterator it = m.keySet().iterator();
        int max = 0;
        long temp = 0;
        while (it.hasNext()) {
            long key = (long) it.next();
            int value = m.get(key);
            if (max < value) {
                max = value;
                temp = key;
            }
        }
        System.out.println(temp);
    }

}