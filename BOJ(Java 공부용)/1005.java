import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int i = 0;i<tc;i++) {
            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int m = Integer.parseInt(input[1]);
            int[] make = new int[n+1];
            int[] indegree = new int[n+1];
            int[] dp = new int[n+1];
            ArrayList<Integer>[] graph = new ArrayList[n+1];
            ArrayDeque<Integer> q = new ArrayDeque<>();
            for(int j=0;j<=n;j++) {
                graph[j] = new ArrayList<>();
            }
            String[] input2 = br.readLine().split(" ");
            for(int j=0;j<input2.length;j++) {
                make[j+1] = Integer.parseInt(input2[j]);
            }
            for(int j=0;j<m;j++) {
                String[] input3 = br.readLine().split(" ");
                int here = Integer.parseInt(input3[0]);
                int next = Integer.parseInt(input3[1]);
                graph[here].add(next);
                indegree[next]++;
            }
            int w = Integer.parseInt(br.readLine().split(" ")[0]);
            for(int j=1;j<=n;j++) {
                if(indegree[j] == 0) {
                    q.add(j);
                    dp[j] = make[j];
                }
            }
            while(!q.isEmpty()) {
                int here = q.poll();
                for(int j=0;j<graph[here].size();j++) {
                    int next = graph[here].get(j);
                    indegree[next]--;
                    if(indegree[next]==0) q.add(next);
                    dp[next] = max(dp[next],dp[here]+make[next]);
                }
            }
            bw.write(dp[w]+"\n");
        }
        bw.flush();
        bw.close();
     }
}