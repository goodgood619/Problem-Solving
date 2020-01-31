import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t = 0, total = 0;
    static ArrayDeque<Integer> st = new ArrayDeque<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int v = Integer.parseInt(input[0]), e = Integer.parseInt(input[1]);
        ArrayList<Integer>[] graph = new ArrayList[v+1];
        int[] dis = new int[v+1];
        int[] scc = new int[v+1];
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for(int i=0;i<=v;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<e;i++) {
            String[] input2 = br.readLine().split(" ");
            int here = Integer.parseInt(input2[0]), next = Integer.parseInt(input2[1]);
            graph[here].add(next);
        }
        for(int i=1;i<=v;i++) {
            if(dis[i] == 0) dfs(i,dis,scc,ans,graph);
        }
        bw.write(total+"\n");
        ans.sort((a, b) -> {
            if (a.get(0) < b.get(0)) return -1;
            else if (a.get(0) > b.get(0)) return 1;
            else return 0;
        });
        for(int i=0;i<ans.size();i++) {
            for(int j=0;j<ans.get(i).size();j++) {
                bw.write(ans.get(i).get(j)+" ");
            }
            bw.write("-1\n");
        }
        bw.flush();
        bw.close();
    }
    private static int dfs(int here,int[] dis,int[] scc,ArrayList<ArrayList<Integer>> ans,ArrayList<Integer>[] graph) {
        dis[here] = ++t;
        int ret = dis[here];
        st.add(here);
        for(int i=0;i<graph[here].size();i++) {
            int next = graph[here].get(i);
            if(dis[next] == 0) ret = min(ret,dfs(next,dis,scc,ans,graph));
            if(scc[next] == 0) ret = min(ret,dis[next]);
        }
        if(ret == dis[here]) {
            ArrayList<Integer> temp = new ArrayList<>();
            while(true) {
                int a = st.peekLast();
                scc[a] = 1;
                temp.add(a);
                st.pollLast();
                if(a == here) break;
            }
            Collections.sort(temp);
            ans.add(temp);
            total++;
        }
        return ret;
    }
}