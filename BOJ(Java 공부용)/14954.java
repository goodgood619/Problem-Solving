import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int p = n;
        Map<Integer, Integer> map = new HashMap<>();
        while (true) {
            if (map.get(p) != null) break;
            if (p == 1) {
                System.out.println("HAPPY");
                return;
            }
            map.put(p, 1);
            String s = String.valueOf(p);
            int temp = 0;
            for (int i = 0; i < s.length(); i++) {
                temp += (s.charAt(i) - '0') * (s.charAt(i) - '0');
            }
            p = temp;
        }
        System.out.println("UNHAPPY");
    }
}