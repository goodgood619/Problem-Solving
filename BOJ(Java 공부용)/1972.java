import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String s = br.readLine();
            if (s.equals("*")) break;
            boolean no = false;
            for (int i = 0; i < s.length() - 2; i++) {
                boolean check = false;
                Map<String, Integer> map = new HashMap<>();
                for (int j = 0; j < s.length(); j++) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(s.charAt(j));
                    if (j + i + 1 < s.length()) sb.append(s.charAt(j + i + 1));
                    if (sb.length() < 2) continue;
                    if (map.get(sb.toString()) == null) {
                        map.put(sb.toString(), 1);
                    } else {
                        check = true;
                        break;
                    }
                }
                if (check) {
                    no = true;
                    break;
                }
            }
            if (!no) bw.write(s + " is surprising.\n");
            else bw.write(s + " is NOT surprising.\n");
        }
        bw.flush();
        bw.close();
    }
}