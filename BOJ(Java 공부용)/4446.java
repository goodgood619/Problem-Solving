import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Character> v = new ArrayList<>();
        v.add('a');
        v.add('i');
        v.add('y');
        v.add('e');
        v.add('o');
        v.add('u');
        List<Character> v2 = new ArrayList<>();
        v2.add('A');
        v2.add('I');
        v2.add('Y');
        v2.add('E');
        v2.add('O');
        v2.add('U');
        List<Character> v3 = new ArrayList<>();
        v3.add('b');
        v3.add('k');
        v3.add('x');
        v3.add('z');
        v3.add('n');
        v3.add('h');
        v3.add('d');
        v3.add('c');
        v3.add('w');
        v3.add('g');
        v3.add('p');
        v3.add('v');
        v3.add('j');
        v3.add('q');
        v3.add('t');
        v3.add('s');
        v3.add('r');
        v3.add('l');
        v3.add('m');
        v3.add('f');
        List<Character> v4 = new ArrayList<>();
        for (Character character : v3) {
            v4.add((char) (character - 32));
        }
        String s;
        while ((s = br.readLine()) != null) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                int idx = 0;
                boolean ok = false;
                for (int j = 0; j < v.size(); j++) {
                    if (v.get(j) == c) {
                        ok = true;
                        idx = j;
                        break;

                    }
                }
                if (ok) {
                    sb.append(v.get((idx - 3 + v.size()) % v.size()));
                    continue;
                }
                idx = 0;
                for (int j = 0; j < v2.size(); j++) {
                    if (v2.get(j) == c) {
                        ok = true;
                        idx = j;
                        break;
                    }
                }
                if (ok) {
                    sb.append(v2.get((idx - 3 + v.size()) % v.size()));
                    continue;
                }
                idx = 0;
                for (int j = 0; j < v3.size(); j++) {
                    if (v3.get(j) == c) {
                        ok = true;
                        idx = j;
                        break;
                    }
                }
                if (ok) {
                    sb.append(v3.get((idx - 10 + v3.size()) % v3.size()));
                    continue;
                }
                idx = 0;
                for (int j = 0; j < v4.size(); j++) {
                    if (v4.get(j) == c) {
                        ok = true;
                        idx = j;
                        break;
                    }
                }
                if (ok) {
                    sb.append(v4.get((idx - 10 + v3.size()) % v3.size()));
                    continue;
                }
                sb.append(c);
            }
            bw.write(sb.toString() + "\n");
        }
        bw.flush();
        bw.close();
    }
}