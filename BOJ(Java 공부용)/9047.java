import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static int min = (int) 1e9;
    static int max = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int cnt = 0;
            while (n != 6174) {
                StringBuilder sb = new StringBuilder();
                sb.append(n);
                if (n < 10) {
                    for (int i = 0; i < 3; i++) sb.append(0);
                } else if (n < 100) {
                    for (int i = 0; i < 2; i++) sb.append(0);
                } else if (n < 1000) {
                    sb.append(0);
                }
                boolean[] tempvisited = new boolean[4];
                min = (int) 1e9;
                max = 0;
                StringBuilder temp = new StringBuilder();
                go(0, 4, sb, temp, tempvisited);
                n = max - min;
                cnt++;
            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static void go(int cnt, int depth, StringBuilder sb, StringBuilder temp, boolean[] visited) {
        if (cnt == depth) {
            int n = Integer.parseInt(temp.toString());
            min = min(min, n);
            max = max(max, n);
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.append(sb.charAt(i));
                go(cnt + 1, depth, sb, temp, visited);
                temp.deleteCharAt(temp.length() - 1);
                visited[i] = false;
            }
        }
    }
}