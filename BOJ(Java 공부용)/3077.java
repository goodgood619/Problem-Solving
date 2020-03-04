import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Map<String, Integer> origin = new HashMap<>();
        String[] cu = new String[n];
        for (int i = 0; i < n; i++) {
            String s = st.nextToken();
            origin.put(s, i);
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            String s = st.nextToken();
            cu[i] = s;
        }
        int ok = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int first = origin.get(cu[i]), second = origin.get(cu[j]);
                if (first < second) ok++;
            }
        }
        int divide = n * (n - 1) / 2;
        bw.write(ok + "/" + divide + " ");
        bw.flush();
        bw.close();
    }
}