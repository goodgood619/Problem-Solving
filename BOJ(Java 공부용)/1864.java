import java.io.*;
import java.util.*;

import static java.lang.Math.pow;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Character, Integer> m = new HashMap<>();
        m.put('-', 0);
        m.put((char) 92, 1);
        m.put('(', 2);
        m.put('@', 3);
        m.put('?', 4);
        m.put('>', 5);
        m.put('&', 6);
        m.put('%', 7);
        m.put('/', -1);
        while (true) {
            String s = br.readLine();
            if (s.charAt(0) == '#' && s.length() == 1) break;
            int sum = 0;
            for (int i = 0; i < s.length(); i++) {
                sum += m.get(s.charAt(i)) * pow(8, s.length() - 1 - i);
            }
            bw.write(sum + "\n");
        }
        bw.flush();
        bw.close();
    }
}