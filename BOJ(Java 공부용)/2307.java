import java.io.*;
import java.util.*;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[] path = new int[n+1];
        ArrayList<p>[] graph = new ArrayList[n+1];
        for(int i=0;i<=n;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[first].add(new p(second,cost));
            graph[second].add(new p(first,cost));
        }
        int curcost = dijk(1,graph,path,n);
        int p = n;
        ArrayList<Integer> v = new ArrayList<>();
        while(p != 1) {
            v.add(p);
            p = path[p];
        }
        v.add(1);
        Collections.reverse(v);
        int max = 0;
        for(int i=0;i<v.size()-1;i++) {
            int here = v.get(i), next= v.get(i+1);
            for(int j=0;j<graph[here].size();j++) {
                if(next == graph[here].get(j).next) {
                    int temp = graph[here].get(j).cost;
                    graph[here].get(j).cost = (int) 1e9;
                    int d = dijk(1,graph,path,n);
                    if(d == -1) {
                        System.out.println(-1);
                        return;
                    }
                    else {
                        max = max(max,d-curcost);
                    }
                    graph[here].get(j).cost = temp;
                    break;
                }
            }
        }
        System.out.println(max);
    }
    private static int dijk(int start,ArrayList<p>[] graph,int[] path,int n) {
        int[] dist = new int[n+1];
        Arrays.fill(dist, (int) 1e9);
        PriorityQueue<p> pq = new PriorityQueue<>((a,b)->{
            if(a.cost<b.cost) return -1;
            else if(a.cost>b.cost) return 1;
            else {
                if(a.next < b.next) return -1;
                else if(a.next>b.next) return 1;
                else return 0;
            }
        });
        dist[start] = 0;
        pq.add(new p(start,0));
        while(!pq.isEmpty()) {
            int here = pq.peek().next;
            int cost = pq.peek().cost;
            pq.poll();
            if(here == n) return cost;
            for(int i=0;i<graph[here].size();i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if(dist[next] >dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    path[next] =here;
                    pq.add(new p(next,dist[next]));
                }
            }
        }
        return -1;
    }
    private static class p {
        int next,cost;
        private p(int next,int cost) {
            this.cost = cost;
            this.next = next;
        }
    }
}