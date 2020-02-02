import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        ArrayList<StringBuilder> v = new ArrayList<>();
        for(int i=0;i<=n;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            StringBuilder st = new StringBuilder();
            st.append(s);
            v.add(st);
        }
        for(int i=0;i<n;i++) {
            StringBuilder s = new StringBuilder();
            s.append(v.get(i));
            boolean[] visited = new boolean[n];
            for(int j=0;j<v.get(i).length();j++) {
                s.append(s.charAt(0));
                s.deleteCharAt(0);
                for(int k=0;k<n;k++) {
                    if(i == k || visited[k]) continue;
                    else {
                        if(s.toString().equals(v.get(k).toString())) {
                            visited[k] = true;
                        }
                    }
                }
            }

            for(int j=0;j<n;j++) {
                if(visited[j]) {
                    graph[i].add(j);
                }
            }
        }
        int cnt = 0;
        boolean[] visited = new boolean[n];
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i,visited,graph);
                cnt++;
            }
        }
        System.out.println(cnt);
    }
    private static void dfs(int here,boolean[] visited,ArrayList<Integer>[] graph) {
        visited[here] = true;
        for(int i=0;i<graph[here].size();i++) {
            int next = graph[here].get(i);
            if(!visited[next]) dfs(next,visited,graph);
        }
    }
}