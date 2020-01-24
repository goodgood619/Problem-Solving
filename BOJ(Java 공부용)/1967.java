import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        ArrayList<p>[] graph = new ArrayList[n+1];
        boolean[] visited = new boolean[n+1];
        for(int i=1;i<=n;i++) {
            graph[i] = new ArrayList<>();
            visited[i] = false;
        }
        for(int i=1;i<n;i++) {
            String[] input2 = br.readLine().split(" ");
            int here = Integer.parseInt(input2[0]);
            int next = Integer.parseInt(input2[1]);
            int cost = Integer.parseInt(input2[2]);
            graph[here].add(new p(next,cost));
            graph[next].add(new p(here,cost));
        }
        dfs(1,0,visited,graph);
        visited = new boolean[n+1];
        Max=0;
        dfs(st,0,visited,graph);
        bw.write(String.valueOf(Max)+"\n");
        bw.flush();
    }
    private static void dfs(int here,int curcost,boolean[] visited,ArrayList<p>[] graph) {
        visited[here] = true;
        if(Max<curcost) {
            Max = curcost;
            st = here;
        }
        for(int i=0;i<graph[here].size();i++) {
            int next = graph[here].get(i).next;
            int nextcost = graph[here].get(i).cost;
            if(!visited[next]) {
                dfs(next,curcost+nextcost,visited,graph);
            }
        }
        visited[here] = false;
    }
    private static class p{
        private int next,cost;
        private p(int next,int cost) {
            this.next = next;
            this.cost = cost;
        }
    }
}
