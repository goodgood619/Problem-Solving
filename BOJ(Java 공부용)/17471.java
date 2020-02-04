import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import static java.lang.Integer.min;
import static java.lang.Math.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,-1,1,0};
    static int[] goy = {1,0,0,-1};
    static int ans = (int) 1e9;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        ArrayList<Integer> v = new ArrayList<>();
        boolean[] visited = new boolean[n+1];
        int[] people = new int[n+1];
        for(int i=0;i<=n;i++) graph[i] = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++) {
            people[i] = Integer.parseInt(st.nextToken());
         }
        for(int i=1;i<=n;i++) {
            st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            for(int j=1;j<=cnt;j++) {
                int next = Integer.parseInt(st.nextToken());
                graph[i].add(next);
            }
        }

        for(int i=1;i<n;i++) {
            dfs(1,0,i,v,visited,n,graph,people);
        }
        System.out.println(ans==(int)1e9?-1:ans);
    }
    private static void dfs(int here,int cnt,int depth,ArrayList<Integer> v,boolean[] visited,int n,ArrayList<Integer>[] graph,int[] people) {
        if(cnt == depth) {
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=1;i<=n;i++) {
                if(!visited[i]) temp.add(i);
            }
            bfs(v,temp,n,graph,people);
            return;
        }
        for(int i=here;i<=n;i++) {
            if(!visited[i]) {
                visited[i] = true;
                v.add(i);
                dfs(i+1,cnt+1,depth,v,visited,n,graph,people);
                v.remove(v.size()-1);
                visited[i] = false;
            }
        }
    }
    private static void bfs(ArrayList<Integer> v, ArrayList<Integer> temp,int n,ArrayList<Integer>[] graph,int[] people) {
        int area = 0;
        boolean[] visited2 = new boolean[n+1];
        for(int i=0;i<v.size();i++) {
            if(!visited2[v.get(i)]) {
                dfs2(v.get(i),v,graph,visited2);
                area++;
            }
        }
        for(int i=0;i<temp.size();i++) {
            if(!visited2[temp.get(i)]) {
                dfs2(temp.get(i),temp,graph,visited2);
                area++;
            }
        }

        if(area == 2) {
            int area1cnt = 0, area2cnt = 0;
            for (int i = 0; i < v.size(); i++) {
                area1cnt += (people[v.get(i)]);
            }
            for (int i = 0; i < temp.size(); i++) {
                area2cnt += (people[temp.get(i)]);
            }
            ans = min(ans, abs(area1cnt - area2cnt));
        }
    }
    private static void dfs2(int here,ArrayList<Integer> v,ArrayList<Integer>[] graph,boolean[] visited2) {
        visited2[here] = true;
        for(int i=0;i<graph[here].size();i++) {
            int next= graph[here].get(i);
            if(!visited2[next]) {
                int ok = 0;
                for(int j =0 ;j<v.size();j++) {
                    if(v.get(j) == next) {
                        ok = 1;
                        break;
                    }
                }
                if(ok == 1) dfs2(next,v,graph,visited2);
            }
        }
    }
}