import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = "ABCDEFGHIJKL";
        String s2 = "0123456789";
        int idx1 = 8, idx2 = 6;
        List<String> v = new ArrayList<>();
        for (int i = 0; i < 60; i++) {
            StringBuilder sb = new StringBuilder();
            sb.append(s.charAt(idx1));
            sb.append(s2.charAt(idx2));
            v.add(sb.toString());
            idx1++;
            idx2++;
            if (idx1 == s.length()) idx1 = 0;
            if (idx2 == s2.length()) idx2 = 0;
        }
        bw.write(v.get(n % 60) + "");
        bw.flush();
        bw.close();
    }
}