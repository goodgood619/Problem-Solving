import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        ArrayList<p>[] graph = new ArrayList[n+1];
        for(int i=1;i<=n;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<m;i++) {
            String[] input2 = br.readLine().split(" ");
            int here = Integer.parseInt(input2[0]), next = Integer.parseInt(input2[1]), cost = Integer.parseInt(input2[2]);
            graph[here].add(new p(next,cost));
            graph[next].add(new p(here,cost));
        }
        String[] input3 = br.readLine().split(" ");
        int st = Integer.parseInt(input3[0]), en = Integer.parseInt(input3[1]);
        int left = 1, right = 2000000005,ans = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(!bfs(graph,st,en,mid,n)) {
                right = mid - 1;
            }
            else {
                ans = mid;
                left = mid +1;
            }
        }
        System.out.println(ans);
    }
    private static boolean bfs(ArrayList<p>[] graph,int st,int en,int mid,int n) {
        boolean[] visited = new boolean[n+1];
        ArrayDeque<pp> q = new ArrayDeque<>();
        q.add(new pp(st,mid));
        visited[st] = true;
        while(!q.isEmpty()) {
            int here = q.peek().here;
            int dist = q.peek().cost;
            if(here == en ) {
                return true;
            }
            q.poll();
            for(int i=0;i<graph[here].size();i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if(dist> nextcost) continue;
                if(!visited[next]) {
                    visited[next] = true;
                    q.add(new pp(next,dist));
                }
            }
        }
        return false;
    }
    private static class pp {
        int here,cost;
        private pp(int here,int cost){
            this.here = here;
            this.cost = cost;
        }
    }
     private static class p {
        int next,cost;
        private p(int next,int cost){
            this.next = next;
            this.cost = cost;
        }
     }
}