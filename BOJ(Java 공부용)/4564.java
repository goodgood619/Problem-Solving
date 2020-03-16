import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            String s = String.valueOf(n);
            List<Integer> v = new ArrayList<>();
            v.add(n);
            while (s.length() != 1) {
                int temp = s.charAt(0) - '0';
                for (int i = 1; i < s.length(); i++) {
                    temp *= (s.charAt(i) - '0');
                }
                v.add(temp);
                s = String.valueOf(temp);
            }
            for (int i = 0; i < v.size(); i++) bw.write(v.get(i) + " ");
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}