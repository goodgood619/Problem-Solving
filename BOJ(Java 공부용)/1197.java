import java.io.*;
import java.util.PriorityQueue;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int v = Integer.parseInt(input[0]);
        int e = Integer.parseInt(input[1]);
        int[] parent = new int[v+1];
        PriorityQueue<p> pq = new PriorityQueue<>((a, b) -> {
            if(a.cost < b.cost) return -1;
            else if(a.cost > b.cost) return 1;
            else {
                if(a.here < b.here) return -1;
                else if(a.here > b.here) return 1;
                else {
                    return 0;
                }
            }
        });
        for(int i=1;i<=v;i++) parent[i] = i;
        for(int i=0;i<e;i++) {
            String[] input2 = br.readLine().split(" ");
            int here = Integer.parseInt(input2[0]);
            int next = Integer.parseInt(input2[1]);
            int cost = Integer.parseInt(input2[2]);
            pq.add(new p(here,next,cost));
        }
        int ans = 0;
        while(!pq.isEmpty()) {
            int here = pq.peek().here;
            int next = pq.peek().next;
            int cost = pq.peek().cost;
            pq.poll();
            if(find(here,parent)!= find(next,parent)) {
                union(here,next,parent);
                ans += cost;
            }
        }
        System.out.println(ans);
    }
    private static class p {
        int here,next,cost;
        private p(int here,int next,int cost) {
            this.here = here;
            this.next = next;
            this.cost = cost;
        }
    }
    private static int find(int u,int[] parent) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u],parent);
    }
    private static void union(int u,int v,int[] parent) {
        u = find(u,parent);
        v = find(v,parent);
        if(u == v) return;
        parent[u] = v;
    }
}