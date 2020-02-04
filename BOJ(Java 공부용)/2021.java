import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] station = new ArrayList[n+1];
        ArrayList<Integer>[] route = new ArrayList[m+1];
        for(int i=0;i<=n;i++) station[i] = new ArrayList<>();
        for(int i=0;i<=m;i++) route[i] = new ArrayList<>();
        for(int i=1;i<=m;i++) {
            st = new StringTokenizer(br.readLine());
            while(true) {
                int num = Integer.parseInt(st.nextToken());
                if(num == -1) break;
                route[i].add(num);
                station[num].add(i);
            }
        }
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
        bw.write(bfs(start,end,station,route,n)+" ");
        bw.flush();
        bw.close();
    }
    private static int bfs(int start,int end,ArrayList<Integer>[] station, ArrayList<Integer>[] route,int n) {
        boolean[] visited = new boolean[n+1];
        boolean[] routevisited = new boolean[n+1];
        int[] dist = new int[n+1];
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(start);
        for(int i=0;i<station[start].size();i++) {
            int h = station[start].get(i);
            routevisited[h] = true;
            for(int j=0;j<route[h].size();j++) {
                q.add(route[h].get(j));
                visited[route[h].get(j)] = true;
            }
        }

        while(!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            if(here == end) return dist[here];
            for(int i=0;i<station[here].size();i++) {
                int nosun = station[here].get(i);
                if(routevisited[nosun]) continue;
                routevisited[nosun] =true;
                for(int j=0;j<route[nosun].size();j++) {
                    if(here == route[nosun].get(j) || visited[route[nosun].get(j)]) continue;
                    if(!visited[route[nosun].get(j)]) {
                        visited[route[nosun].get(j)] = true;
                        q.add(route[nosun].get(j));
                        dist[route[nosun].get(j)] = dist[here] + 1;
                        if(route[nosun].get(j) == end) {
                            return dist[route[nosun].get(j)];
                        }
                    }
                }
            }
        }
        return -1;
    }
}