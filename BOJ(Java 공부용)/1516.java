import java.io.*;
import java.util.*;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        int[] indegree = new int[n + 1];
        int[] make = new int[n + 1];
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            make[i] = Integer.parseInt(st.nextToken());
            while (true) {
                int num = Integer.parseInt(st.nextToken());
                if (num == -1) break;
                graph[num].add(i);
                indegree[i]++;
            }
        }
        ArrayDeque<Integer> q = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                dp[i] = make[i];
                q.add(i);
            }
        }
        while (!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i);
                indegree[next]--;
                if (indegree[next] == 0) q.add(next);
                dp[next] = max(dp[next], dp[here] + make[next]);
            }
        }
        for (int i = 1; i <= n; i++) bw.write(dp[i] + "\n");
        bw.flush();
        bw.close();
    }
}