import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Long.max;
import static java.lang.Long.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static long max = 0;
    static long min = (long) 1e11;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        boolean[] visited = new boolean[10];
        ArrayList<Character> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            v.add(st.nextToken().charAt(0));
        }
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 10; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sb.append(i);
                go(0, n, sb, visited, v);
                sb.deleteCharAt(sb.length() - 1);
                visited[i] = false;
            }
        }
        if (String.valueOf(max).length() != String.valueOf(min).length()) System.out.println(max + "\n" + "0" + min);
        else System.out.println(max + "\n" + min);
    }

    private static void go(int cnt, int depth, StringBuilder sb, boolean[] visited, ArrayList<Character> v) {
        if (cnt == depth) {
            max = max(max, Long.parseLong(sb.toString()));
            min = min(min, Long.parseLong(sb.toString()));
            return;
        }
        for (int i = 0; i < 10; i++) {
            char c = v.get(cnt);
            int prenum = sb.charAt(cnt) - '0';
            if (c == '<' && prenum > i || c == '>' && prenum < i) continue;
            if (!visited[i]) {
                visited[i] = true;
                sb.append(i);
                go(cnt + 1, depth, sb, visited, v);
                sb.deleteCharAt(sb.length() - 1);
                visited[i] = false;
            }
        }
    }
}