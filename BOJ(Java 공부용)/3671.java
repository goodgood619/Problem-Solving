import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[10000001];
        notprime[0] = true;
        notprime[1] = true;
        for (int i = 2; i <= sqrt(10000000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 10000000; j += i) notprime[j] = true;
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            String s = br.readLine();
            HashMap<Integer, Integer> cnt = new HashMap<>();
            boolean[] visited = new boolean[s.length()];
            for (int i = 1; i <= visited.length; i++) {
                go(0, 0, i, visited, cnt, notprime, s);
            }
            bw.write(cnt.size() + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static void go(int index, int c, int depth, boolean[] visited, HashMap<Integer, Integer> cnt, boolean[] notprime, String s) {
        if (c == depth) {
            ArrayList<Character> v = new ArrayList<>();
            for (int i = 0; i < visited.length; i++) {
                if (visited[i]) v.add(s.charAt(i));
            }
            boolean[] visited2 = new boolean[v.size()];
            StringBuilder sb = new StringBuilder();
            go2(0, v.size(), visited2, v, sb, notprime, cnt);
            return;
        }
        for (int i = index; i < visited.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                go(i + 1, c + 1, depth, visited, cnt, notprime, s);
                visited[i] = false;
            }
        }
    }

    private static void go2(int cnt, int depth, boolean[] visited, ArrayList<Character> v, StringBuilder sb, boolean[] notprime, HashMap<Integer, Integer> map) {
        if (cnt == depth) {
            int num = Integer.parseInt(sb.toString());
            if (notprime[num]) return;
            if (map.get(num) == null) {
                map.put(num, 1);
            }
            return;
        }
        for (int i = 0; i < visited.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sb.append(v.get(i));
                go2(cnt + 1, depth, visited, v, sb, notprime, map);
                visited[i] = false;
                sb.deleteCharAt(sb.length() - 1);
            }
        }
    }
}