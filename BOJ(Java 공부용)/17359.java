import java.io.*;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Integer.min;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] visited = new boolean[n];
        List<p> v = new ArrayList<>();
        List<p> temp = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String s = br.readLine();
            v.add(new p(s, cal(s)));
        }
        go(0, n, v, visited, temp);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void go(int cnt, int depth, List<p> v, boolean[] visited, List<p> temp) {
        if (cnt == depth) {
            int total = 0;
            for (int i = 0; i < temp.size() - 1; i++) {
                String here = temp.get(i).s;
                String next = temp.get(i + 1).s;
                if (here.charAt(here.length() - 1) != next.charAt(0)) total++;
                total += temp.get(i).sum;
            }
            total += temp.get(temp.size() - 1).sum;
            ans = min(ans, total);
            return;
        }
        for (int i = 0; i < v.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.add(v.get(i));
                go(cnt + 1, depth, v, visited, temp);
                temp.remove(temp.size() - 1);
                visited[i] = false;
            }
        }
    }

    private static int cal(String s) {
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) != s.charAt(i + 1)) sum++;
        }
        return sum;
    }
}

class p {
    String s;
    int sum;

    p(String s, int sum) {
        this.s = s;
        this.sum = sum;
    }
}