import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        int[][] par = new int[n + 1][18];
        int[] d = new int[n + 1];
        boolean[] visited = new boolean[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
            visited[i] = false;
            d[i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 17; j++) {
                par[i][j] = 0;
            }
        }
        for(int i=0;i<n-1;i++) {
            String[] input = br.readLine().split(" ");
            int here = Integer.parseInt(input[0]);
            int next = Integer.parseInt(input[1]);
            graph[here].add(next);
            graph[next].add(here);
        }
        dfs(1,0,0,graph,visited,par,d);
        make(n,par);
        int m = Integer.parseInt(br.readLine());
        for(int i=0;i<m;i++) {
            String[] input2 = br.readLine().split(" ");
            ArrayList<p> ans = new ArrayList<>();
            int r = Integer.parseInt(input2[0]);
            int u = Integer.parseInt(input2[1]);
            int v = Integer.parseInt(input2[2]);
            int lca1 = lca(r,u,d,par);
            int lca2 = lca(r,v,d,par);
            int lca3 = lca(u,v,d,par);
            ans.add(new p(d[lca1],lca1));
            ans.add(new p(d[lca2],lca2));
            ans.add(new p(d[lca3],lca3));
            Collections.sort(ans, new Comparator<p>() {
                @Override
                public int compare(p a, p b) {
                    if(a.depth > b.depth) return -1;
                    else if(a.depth<b.depth) return 1;
                    return 0;
                }
            });
            bw.write(String.valueOf(ans.get(0).cur)+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static class p{
        int depth,cur;
        private p(int depth,int cur) {
            this.cur = cur;
            this.depth = depth;
        }
    }
    private static void dfs(int here,int parent,int depth,ArrayList<Integer>[] graph,boolean[] visited,int[][] par, int[] d) {
        visited[here] = true;
        d[here] = depth;
        par[here][0] = parent;
        for(int i=0;i<graph[here].size();i++) {
            int next = graph[here].get(i);
            if(!visited[next]) {
                dfs(next,here,depth+1,graph,visited,par,d);
            }
        }
    }
    private static void make(int n,int[][] par) {
        for(int j=1;j<=17;j++) {
            for(int i=1;i<=n;i++) {
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }
    private static int lca(int a,int b,int[] d, int[][] par) {
        if(d[a]>d[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        for(int i=17;i>=0;i--) {
            if(d[b]-d[a]>=(1<<i)) {
                b = par[b][i];
            }
        }
        if(a==b) return a;
        for(int i=17;i>=0;i--) {
            if(par[a][i] != par[b][i]) {
                a= par[a][i];
                b= par[b][i];
            }
        }
        return par[a][0];
    }
}
