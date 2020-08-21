import java.util.*;
class Solution {
    int D=0;
    Map<Integer,Integer> map = new HashMap<>();
    public int solution(int n, int[][] edge) {
        List<Integer>[] graph = new ArrayList[n+1];
        for(int i=1;i<=n;i++) graph[i] = new ArrayList<>();
        boolean[] visited = new boolean[n+1];
        for(int i=0;i<edge.length;i++) {
            int here = edge[i][0];
            int next = edge[i][1];
            graph[here].add(next);
            graph[next].add(here);
        }
        bfs(1,0,graph,visited);
        return map.get(D);
    }
    private void bfs(int start,int depth,List<Integer>[] graph,boolean[] visited) {
        Deque<P> q = new ArrayDeque<>();
        q.add(new P(start,0));
        visited[start]=true;
        while(!q.isEmpty()) {
            int here= q.peek().here;
            int dist = q.peek().dist;
            D = Math.max(D,dist);
            if(map.get(dist)==null) {
                map.put(dist,1);
            }
            else {
                int value = map.get(dist);
                value++;
                map.remove(dist);
                map.put(dist,value);
            }
            q.poll();
            for(Integer e : graph[here]) {
                int next = (int)e;
                if(!visited[next]) {
                    visited[next]=true;
                    q.add(new P(next,dist+1));
                }
            }
        }
    }
}
class P {
    int here,dist;
    P(int here,int dist) {
        this.here = here;
        this.dist = dist;
    }
}