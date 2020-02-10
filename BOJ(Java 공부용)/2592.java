import java.io.*;
import java.util.Iterator;
import java.util.TreeMap;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        TreeMap<Integer, Integer> m = new TreeMap<>();
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            int num = Integer.parseInt(br.readLine());
            sum += num;
            if (m.get(num) == null) m.put(num, 1);
            else {
                int value = m.get(num);
                value++;
                m.remove(num);
                m.put(num, value);
            }
        }
        sum /= 10;
        int max = 0, num = 0;
        Iterator it = m.keySet().iterator();
        while (it.hasNext()) {
            int key = (int) it.next();
            if (max < m.get(key)) {
                max = m.get(key);
                num = key;
            }
        }
        System.out.println(sum + "\n" + num);

    }

}