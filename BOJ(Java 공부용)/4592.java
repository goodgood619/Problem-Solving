import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) break;
            ArrayList<Integer> v = new ArrayList<>();
            int first = Integer.parseInt(st.nextToken());
            v.add(first);
            for (int i = 1; i < n; i++) {
                int num = Integer.parseInt(st.nextToken());
                if (first == num) continue;
                v.add(num);
                first = num;
            }
            for (int i = 0; i < v.size(); i++) bw.write(v.get(i) + " ");
            bw.write("$\n");
        }
        bw.flush();
        bw.close();
    }
}