import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] indegree = new int[n + 1];
            ArrayList<Integer>[] graph = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                int num = Integer.parseInt(st.nextToken());
                graph[i].add(num);
                indegree[num]++;
            }
            ArrayDeque<Integer> q = new ArrayDeque<>();
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (indegree[i] == 0) {
                    q.add(i);
                }
            }
            while (!q.isEmpty()) {
                int here = q.peek();
                q.poll();
                cnt++;
                for (int i = 0; i < graph[here].size(); i++) {
                    int next = graph[here].get(i);
                    indegree[next]--;
                    if (indegree[next] == 0) q.add(next);
                }
            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }
}