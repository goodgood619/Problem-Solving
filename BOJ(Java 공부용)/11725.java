import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        boolean[] visited = new boolean[n+1];
        int[] parent = new int[n+1];
        for(int i=0;i<=n;i++) graph[i] = new ArrayList<>();
        for(int i=1;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken());
            graph[here].add(next);
            graph[next].add(here);
        }
        dfs(1,0,graph,visited,parent);
        for(int i=2;i<=n;i++) bw.write(parent[i]+"\n");
        bw.flush();
        bw.close();
    }
    private static void dfs(int here,int pre,ArrayList<Integer>[] graph,boolean[] visited,int[] parent) {
        visited[here] = true;
        parent[here] = pre;
        for(int i=0;i<graph[here].size();i++) {
            int next = graph[here].get(i);
            if(!visited[next]) {
                dfs(next,here,graph,visited,parent);
            }
        }
    }
}