import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";
        while ((s = br.readLine()) != null) {
            List<Integer> v = new ArrayList<>();
            StringTokenizer st= new StringTokenizer(s);
            int n = Integer.parseInt(st.nextToken());
            boolean[] check = new boolean[3000];
            for (int i = 0; i < n; i++) {
                v.add(Integer.parseInt(st.nextToken()));
            }
            if (v.size() == 1) {
                bw.write("Jolly\n");
            } else {
                for (int i = 0; i < v.size() - 1; i++) {
                    check[abs(v.get(i) - v.get(i + 1))] = true;
                }
                boolean no = false;
                for (int i = 1; i < n; i++) {
                    if (!check[i]) {
                        bw.write("Not jolly\n");
                        no = true;
                        break;
                    }
                }
                if (!no) bw.write("Jolly\n");
            }
        }
        bw.flush();
        bw.close();
    }
}