import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int st = Integer.parseInt(input[2]);
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        boolean visited[] = new boolean[n+1];
        for(int i=1;i<=n;i++) {
            graph[i] = new ArrayList<>();
        }
        for(int i=0;i<m;i++) {
            String[] s = br.readLine().split(" ");
            int here = Integer.parseInt(s[0]);
            int next = Integer.parseInt(s[1]);
            graph[here].add(next);
            graph[next].add(here);
        }
        for(int i=1;i<=n;i++) {
            Collections.sort(graph[i]);
        }
        dfs(st,graph,visited);
        System.out.println();
        visited = new boolean[n+1];
        bfs(st,graph,visited);
        bw.close();
    }
    private static void dfs(int here, ArrayList<Integer>[] graph, boolean[] visited) throws IOException {
        visited[here] = true;
        bw.write(String.valueOf(here)+" ");
        bw.flush();
        for(int i=0;i<graph[here].size();i++) {
            int next = graph[here].get(i);
            if(!visited[next]) dfs(next,graph,visited);
        }
    }
    private static void bfs(int here,ArrayList<Integer>[] graph,boolean[] visited) throws IOException {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(here);
        visited[here] = true;
        while(!q.isEmpty()) {
            int Here = q.peekFirst();
            bw.write(String.valueOf(Here)+" ");
            bw.flush();
            q.pop();
            for(int i=0;i<graph[Here].size();i++){
                int next = graph[Here].get(i);
                if(!visited[next]) {
                    visited[next] = true;
                    q.add(next);
                }
            }
        }
     }
}
