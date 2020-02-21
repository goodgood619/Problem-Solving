import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            int p = n / 2;
            if (n % 2 == 1) p++;
            ArrayList<String> v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String s = br.readLine();
                v.add(s);
            }

            for (int i = 0, j = p; j < v.size(); i++, j++) {
                bw.write(v.get(i) + "\n");
                bw.write(v.get(j) + "\n");
            }
            p--;
            if (n % 2 == 1) bw.write(v.get(p) + "\n");
        }
        bw.flush();
        bw.close();
    }
}