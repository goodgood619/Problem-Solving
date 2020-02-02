import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int cnt = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        for(int i=0;i<=n;i++) graph[i] = new ArrayList<>();
        String[] input = br.readLine().split(" ");
        boolean[] visited = new boolean[n+1];
        int st = -1;
        for(int i=0;i<input.length;i++) {
            int par = Integer.parseInt(input[i]);
            if(par == -1) st = i;
            else graph[par].add(i);
        }
        int del = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int i=0;i<n;i++) {
            for(int j=0;j<graph[i].size();j++) {
                int next = graph[i].get(j);
                if(del == next) {
                    graph[i].remove(j);
                }
            }
        }
        dfs(st,graph,visited);
        System.out.println(del==st?0:cnt);
    }
    private static void dfs(int here,ArrayList<Integer>[] graph,boolean[] visited) {
        if(graph[here].size() == 0) cnt++;
        visited[here] = true;
        for(int i=0;i<graph[here].size();i++) {
            int next = graph[here].get(i);
            if(!visited[next]) dfs(next,graph,visited);
        }
    }
}