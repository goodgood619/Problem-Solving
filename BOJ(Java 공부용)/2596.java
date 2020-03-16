import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Character> map = new HashMap<>();
        map.put("000000", 'A');
        map.put("001111", 'B');
        map.put("010011", 'C');
        map.put("011100", 'D');
        map.put("100110", 'E');
        map.put("101001", 'F');
        map.put("110101", 'G');
        map.put("111010", 'H');
        String s = br.readLine();
        StringBuilder sb = new StringBuilder();
        for (int i = 0, p = 1; i < s.length(); i += 6, p++) {
            String temp = s.substring(i, i + 6);
            boolean same = false;
            for (String element : map.keySet()) {
                if (temp.equals(element)) {
                    same = true;
                    sb.append(map.get(element));
                    break;
                }
            }
            if (!same) {
                boolean check = false;
                for (String element : map.keySet()) {
                    int cnt = 0;
                    for (int j = 0; j < temp.length(); j++) {
                        if (temp.charAt(j) == element.charAt(j)) continue;
                        cnt++;
                    }
                    if (cnt <= 1) {
                        check = true;
                        sb.append(map.get(element));
                        break;
                    }
                }
                if (!check) {
                    System.out.println(p);
                    return;
                }
            }
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}