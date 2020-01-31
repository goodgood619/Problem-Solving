import java.io.*;
import java.util.ArrayList;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int z = 0;z<tc;z++) {
            int n = Integer.parseInt(br.readLine().split(" ")[0]);
            boolean[] visited = new boolean[n];
            ArrayList<p> arr = new ArrayList<>();
            ArrayList<Integer>[] graph = new ArrayList[n];
            for(int i=0;i<n;i++) graph[i] = new ArrayList<>();
            for(int i=0;i<n;i++) {
                String[] input = br.readLine().split(" ");
                int first = Integer.parseInt(input[0]), second = Integer.parseInt(input[1]), third = Integer.parseInt(input[2]);
                arr.add(new p(first, second, third));
            }

            for(int i=0;i<n;i++) {
                for(int j=i;j<n;j++) {
                    if(i != j) {
                        int x = arr.get(i).first - arr.get(j).first;
                        int y = arr.get(i).second - arr.get(j).second;
                        double dist = sqrt(x*x+y*y);
                        double range = (double)arr.get(i).third +(double)arr.get(j).third;
                        if(range >= dist ) {
                            graph[i].add(j);
                            graph[j].add(i);
                        }
                    }
                }
            }

            int group = 0;
            for(int i=0;i<n;i++) {
                if(!visited[i]) {
                    dfs(i,visited,graph);
                    group++;
                }
            }
            bw.write(group+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static void dfs(int here,boolean[] visited, ArrayList<Integer>[] graph) {
        visited[here] = true;
        for(int i=0;i<graph[here].size();i++) {
            int next = graph[here].get(i);
            if(!visited[next]) dfs(next,visited,graph);
        }
    }
    private static class p {
        int first,second,third;
        private p(int first,int second,int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }
}