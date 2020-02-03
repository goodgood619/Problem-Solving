import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int tc = 0;tc<t;tc++) {
            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]);
            int[] path = new int[1001];
            ArrayList<Integer>[] graph = new ArrayList[m+1];
            for(int i=0;i<=m;i++) graph[i] = new ArrayList<>();
            for(int i=1;i<=m;i++) {
                String[] input2 = br.readLine().split(" ");
                int first = Integer.parseInt(input2[0]), second = Integer.parseInt(input2[1]);
                for(int j = first;j<=second;j++) {
                    graph[i].add(j);
                }
            }
            int ans = 0;
            for(int i=0;i<=1000;i++) path[i] = -1;
            for(int i=1;i<=m;i++) {
                boolean[] visited = new boolean[1001];
                int ok = dfs(i,graph,path,visited);
                if(ok == 1) ans++;
            }
            bw.write(ans+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static int dfs(int here, ArrayList<Integer>[] graph, int[] path, boolean[] visited) {
        if(visited[here]) return 0;
        visited[here] = true;
        for(int i=0;i<graph[here].size();i++) {
            int next = graph[here].get(i);
            if(path[next] == -1) {
                path[next] = here;
                return 1;
            }
            else if(dfs(path[next],graph,path,visited) == 1) {
                path[next] = here;
                return 1;
            }
        }
        return 0;
    }
}