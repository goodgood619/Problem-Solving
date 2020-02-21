import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        HashMap<Integer, String> map1 = new HashMap<>();
        HashMap<String, Integer> map2 = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            String s = br.readLine();
            map1.put(i, s);
            map2.put(s, i);
        }
        for (int i = 0; i < m; i++) {
            String s = br.readLine();
            if (s.charAt(0) >= '1' && s.charAt(0) <= '9') {
                int a = Integer.parseInt(s);
                bw.write(map1.get(a) + "\n");
            } else {
                bw.write(map2.get(s) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}