import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {-1,1,2};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        ArrayList<p>[] graph= new ArrayList[n+1];
        ArrayList<Integer> ans = new ArrayList<>();
        int[] path = new int[n+1];
        for(int i=0;i<=n;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[here].add(new p(next,cost));
        }
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
        bw.write(dijk(start,end,graph,n,path)+"\n");
        int p = end;
        while(p != 0) {
            ans.add(p);
            p = path[p];
        }
        bw.write(ans.size()+"\n");
        for(int i=ans.size()-1;i>=0;i--) bw.write(ans.get(i)+" ");
        bw.flush();
        bw.close();
    }
    private static int dijk(int start,int end,ArrayList<p>[] graph,int n,int[] path) {
        int[] dist = new int[n+1];
        for(int i=1;i<=n;i++) dist[i] = (int) 1e9;
        dist[start] = 0;
        PriorityQueue<pp> pq = new PriorityQueue<>((a,b)->{
            if(a.cost<b.cost) return -1;
            else if(a.cost>b.cost) return 1;
            else {
                if(a.st<b.st) return -1;
                else if(a.st>b.st) return 1;
                else return 0;
            }
        });

        pq.add(new pp(start,0));
        while (!pq.isEmpty()) {
            int here = pq.peek().st;
            int cost = pq.peek().cost;
            pq.poll();
            if(cost > dist[here]) continue;
            for(int i=0;i<graph[here].size();i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if(dist[next]>dist[here]+nextcost){
                    dist[next] = dist[here] +nextcost;
                    path[next] = here;
                    pq.add(new pp(next,dist[next]));
                }
            }
        }
        return dist[end];
    }
    private static class pp {
        int st,cost;
        private pp(int st,int cost){
            this.cost = cost;
            this.st = st;
        }
    }
    private static class p {
        int next,cost;
        private p(int next,int cost) {
            this.next = next;
            this.cost = cost;
        }
    }
}