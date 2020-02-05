import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<p>[] graph = new ArrayList[n+1];
        for(int i=0;i<=n;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            char here = input[0].charAt(0);
            char left = input[1].charAt(0);
            char right = input[2].charAt(0);

            if(left == '.' && right !='.') {
                graph[here-'A'].add(new p(-1,right-'A'));
            }
            else if(left !='.' && right == '.') {
                graph[here-'A'].add(new p(left-'A',-1));
            }
            else if(left == '.' && right == '.') {
                graph[here-'A'].add(new p(-1,-1));
            }
            else {
                graph[here-'A'].add(new p(left-'A',right-'A'));
            }
        }
        dfs1(0,graph);
        bw.write("\n");
        dfs2(0,graph);
        bw.write("\n");
        dfs3(0,graph);
        bw.flush();
        bw.close();
    }
    private static void dfs1(int here,ArrayList<p>[] graph) throws IOException {
        bw.write(here+'A');
        if(graph[here].get(0).left != -1) dfs1(graph[here].get(0).left,graph);
        if(graph[here].get(0).right != -1) dfs1(graph[here].get(0).right,graph);
    }
    private static void dfs2(int here,ArrayList<p>[] graph) throws IOException {
        if(graph[here].get(0).left != -1) dfs2(graph[here].get(0).left,graph);
        bw.write(here+'A');
        if(graph[here].get(0).right != -1) dfs2(graph[here].get(0).right,graph);
    }
    private static void dfs3(int here,ArrayList<p>[] graph) throws IOException {
        if(graph[here].get(0).left != -1) dfs3(graph[here].get(0).left,graph);
        if(graph[here].get(0).right != -1) dfs3(graph[here].get(0).right,graph);
        bw.write(here+'A');
    }
    private static class p {
        int left,right;
        private p(int left,int right) {
            this.left = left;
            this.right = right;
        }
    }
}