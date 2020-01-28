import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int[] arr = new int[n+1];
        int[] parent = new int[n+1];
        for(int i=0;i<=n;i++) parent[i] = i;
        for(int i=0;i<m;i++) {
            String[] input2 = br.readLine().split(" ");
            int what = Integer.parseInt(input2[0]);
            int a = Integer.parseInt(input2[1]);
            int b = Integer.parseInt(input2[2]);
            if(what == 0 ){
                union(a,b,parent);
            }
            else {
                if (find(a, parent) == find(b, parent)) {
                    bw.write("YES\n");
                } else {
                    bw.write("NO\n");
                }
            }
        }
        bw.flush();
        bw.close();
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