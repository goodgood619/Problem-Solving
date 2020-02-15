import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        ArrayList<String> v = new ArrayList<>();
        for (int i = 1; i < s.length() - 2; i++) {
            for (int j = i + 1; j < s.length(); j++) {
                String a = s.substring(0, i);
                String b = s.substring(i, j);
                String c = s.substring(j, s.length());
                StringBuilder sb = new StringBuilder();
                for (int r = a.length() - 1; r >= 0; r--) sb.append(a.charAt(r));
                for (int r = b.length() - 1; r >= 0; r--) sb.append(b.charAt(r));
                for (int r = c.length() - 1; r >= 0; r--) sb.append(c.charAt(r));
                v.add(sb.toString());
            }
        }
        Collections.sort(v);
        bw.write(v.get(0));
        bw.flush();
        bw.close();
    }
}