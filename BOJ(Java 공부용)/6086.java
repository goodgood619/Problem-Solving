import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int cnt = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<Edge>[] graph = new ArrayList[55];
        for(int i=0;i<=54;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            char first = input[0].charAt(0), second = input[1].charAt(0);
            int water = Integer.parseInt(input[2]);
            int one = gogo(first), two = gogo(second);
            Edge newedge1 = new Edge(two,water);
            Edge newedge2 = new Edge(one,water);
            newedge1.reverse = newedge2;
            newedge2.reverse = newedge1;
            graph[one].add(newedge1);
            graph[two].add(newedge2);
        }
        int total = 0;
        int source = 1;
        int sink = 26;

        while(true) {
            int[] pre = new int[55];
            Arrays.fill(pre,-1);
            Edge[] path = new Edge[55];
            for(int i=0;i<=54;i++) path[i] = new Edge(0,0);
            ArrayDeque<Integer> q = new ArrayDeque<>();
            q.add(source);
            while(!q.isEmpty()) {
                int here = q.peek();
                if(here == sink) break;
                q.poll();
                for(int i=0;i<graph[here].size();i++) {
                    int next = graph[here].get(i).target;
                    if(graph[here].get(i).spare()>0 && pre[next] == -1) {
                        q.add(next);
                        pre[next] = here;
                        path[next] = graph[here].get(i);
                    }
                }
            }
            if(pre[sink]== -1) break;
            int minflow = (int) 1e9;
            for(int i= sink ;i!=source;i = pre[i]) {
                minflow = min(minflow,path[i].spare());
            }
            for(int i=sink;i!=source;i=pre[i]) {
                path[i].goflow(minflow);
            }
            total += minflow;
        }
        System.out.println(total);
    }
    private static int gogo(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
        else return c - 'Z' + 20;
    }
    private static class Edge {
        int target,capacity,flow;
        private Edge reverse;
        private Edge(int target,int capacity) {
            this.target = target;
            this.capacity = capacity;
            this.flow = 0;
            this.reverse = null;
        }
        int spare() { return this.capacity-this.flow;}
        void goflow(int flow) {
            this.flow += flow;
            this.reverse.flow -= flow;
        }
    }
}