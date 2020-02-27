import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        HashMap<String, Integer> map = new HashMap<>();
        HashMap<String, Integer> wrong = new HashMap<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            String who = st.nextToken();
            int what = Integer.parseInt(st.nextToken()), memory = Integer.parseInt(st.nextToken()), time = Integer.parseInt(st.nextToken()), lang = Integer.parseInt(st.nextToken()), code = Integer.parseInt(st.
                    nextToken());
            if (who.equals("megalusion")) continue;
            if (what == 4) {
                map.putIfAbsent(who, 1);
            } else {
                if (map.get(who) != null) continue;
                if (wrong.get(who) == null) {
                    wrong.put(who, 1);
                } else {
                    int value = wrong.get(who);
                    value++;
                    wrong.remove(who);
                    wrong.put(who, value);
                }
            }
        }

        if (map.size() == 0) {
            System.out.println(0);
        } else {
            int correct = map.size(), wrongtotal = 0;
            for (String s : wrong.keySet()) {
                if (map.get(s) == null) continue;
                wrongtotal += wrong.get(s);
            }
            System.out.printf("%.9f", (double) correct / (correct + wrongtotal) * 100);
        }
    }
}