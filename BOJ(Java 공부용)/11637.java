import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            List<Integer> v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                v.add(Integer.parseInt(br.readLine()));
            }
            int total = 0, max = 0, idx = -1;
            for (int i = 0; i < v.size(); i++) {
                total += v.get(i);
                if (max < v.get(i)) {
                    max = v.get(i);
                    idx = i;
                }
            }
            boolean no = false;
            for (int i = 0; i < v.size(); i++) {
                if (max == v.get(i) && idx != i) {
                    no = true;
                    break;
                }
            }
            if (no) {
                System.out.println("no winner");
                continue;
            }
            double ret = max / (double) total;
            if (ret > 0.5) {
                System.out.println("majority winner " + (idx + 1));
            } else System.out.println("minority winner " + (idx + 1));

        }

    }
}