import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int v = Integer.parseInt(input[0]);
        int e = Integer.parseInt(input[1]);
        ArrayList<p>[] graph = new ArrayList[v+1];
        for(int i=1;i<=v;i++) {
            graph[i] = new ArrayList<>();
        }
        int st = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int i=0;i<e;i++) {
            String[] input2 = br.readLine().split(" ");
            int here = Integer.parseInt(input2[0]);
            int next = Integer.parseInt(input2[1]);
            int cost = Integer.parseInt(input2[2]);
            graph[here].add(new p(next,cost));
        }
        dijk(st,v,graph);
    }
    private static void dijk(int st,int v,ArrayList<p>[] graph) throws IOException {
        PriorityQueue<pp> pq = new PriorityQueue<>(new Comparator<pp>() {
            @Override
            public int compare(pp a, pp b) {
                if(a.cost < b.cost) {
                    return -1; // 음수 반환이 우선순위가 높은것, 즉 cost를 오름차순하기 위해서 a가 더 작음
                }
                else if(a.cost > b.cost) {
                    return 1;
                }
                else {
                    if(a.here<b.here) return -1;
                    else return 1;
                }
            }
        });
        int[] dist = new int[v+1];
        for(int i=1;i<=v;i++) dist[i] = Integer.MAX_VALUE;
        dist[st] =0;
        pq.add(new pp(st,0));
        while(!pq.isEmpty()) {
            int here = pq.peek().here;
            int cost = pq.peek().cost;
            pq.poll();
            if(dist[here]<cost) continue;
            for(int i=0;i<graph[here].size();i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if(dist[next]>dist[here]+nextcost) {
                    dist[next] = dist[here]+nextcost;
                    pq.add(new pp(next,dist[next]));
                }
            }
        }

        for(int i=1;i<=v;i++) {
            if(dist[i]==Integer.MAX_VALUE) bw.write("INF\n");
            else bw.write(String.valueOf(dist[i])+"\n");
        }
        bw.flush();
    }
    private static class pp{
        int here,cost;
        private pp(int here,int cost) {
            this.here = here;
            this.cost = cost;
        }
    }
    private static class p{
        int next,cost;
        private p(int next,int cost) {
            this.next = next;
            this.cost = cost;
        }
    }
}