import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        ArrayList<p>[] graph= new ArrayList[n+1];
        for(int i=0;i<=n;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[here].add(new p(next,cost));
            graph[next].add(new p(here,cost));
        }
        for(int i=1;i<=n;i++) {
            int[] dist = new int[n+1];
            int[] path = new int[n+1];
            Arrays.fill(dist, (int) 1e9);
            dijk(i,dist,path,graph);
            for(int j=1;j<=n;j++) {
                if(i == j) bw.write("- ");
                else {
                    boolean check = false;
                    int p = path[j],idx = 0;
                    while(p!=i) {
                        idx = p;
                        p = path[p];
                        check = true;
                    }
                    if(check) bw.write(idx+" ");
                    else bw.write(j+" ");
                }
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
    private static void dijk(int start,int[] dist, int[] path,ArrayList<p>[] graph) {
        dist[start] = 0;
        PriorityQueue<pp> pq = new PriorityQueue<>((a,b)->{
           if(a.cost<b.cost) return -1;
           else if(a.cost>b.cost) return 1;
           else {
               if(a.here<b.here) return -1;
               else if(a.here>b.here) return 1;
               else return 0;
           }
        });
        pq.add(new pp(start,0));
        while(!pq.isEmpty()) {
            int here = pq.peek().here;
            int cost = pq.peek().cost;
            pq.poll();
            if(cost > dist[here]) continue;
            for(int i=0;i<graph[here].size();i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if(dist[next]>dist[here]+nextcost) {
                    dist[next] = dist[here] +nextcost;
                    pq.add(new pp(next,dist[next]));
                    path[next] = here;
                }
            }
        }
    }
    static class pp {
        int here,cost;
        pp(int here,int cost) {
            this.here = here;
            this.cost = cost;
        }
    }
    static class p {
        int next,cost;
        p(int next,int cost) {
            this.cost = cost;
            this.next = next;
        }
    }
}