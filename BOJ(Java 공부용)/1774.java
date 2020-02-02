import java.io.*;
import java.util.*;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]);
        ArrayList<p> v = new ArrayList<>();
        int[] parent = new int[1001];
        PriorityQueue<pp> pq = new PriorityQueue<>((a, b) -> {
            if(a.dist <b.dist) return -1;
            else if(a.dist>b.dist) return 1;
            else {
                if(a.x <b.x) return -1;
                else if(a.x >b.x) return 1;
                else {
                    if(a.y<b.y) return -1;
                    else if(a.y>b.y) return 1;
                    else return 0;
                }
            }
        });
        for(int i=0;i<=1000;i++) parent[i] = i;
        for(int i=0;i<n;i++) {
            String[] input2 = br.readLine().split(" ");
            v.add(new p(Double.parseDouble(input2[0]),Double.parseDouble(input2[1])));
        }
        int cnt = 0;
        for(int i=0;i<m;i++) {
            String[] input3 = br.readLine().split(" ");
            int a = Integer.parseInt(input3[0]), b= Integer.parseInt(input3[1]);
            if(find(a,parent)!= find(b,parent)) {
                union(a,b,parent);
                cnt++;
            }
        }

        for(int i=0;i<v.size();i++) {
            for(int j=i+1;j<v.size();j++) {
                double x = pow(v.get(i).x-v.get(j).x,2.0);
                double y = pow(v.get(i).y-v.get(j).y,2.0);
                double res = sqrt(x+y);
                pq.add(new pp(res,i+1,j+1));
            }
        }
        double sum = 0;
        while(cnt != n-1) {
            double dist = pq.peek().dist;
            int x = pq.peek().x;
            int y = pq.peek().y;
            pq.poll();
            if(find(x,parent)!=find(y,parent)) {
                union(x,y,parent);
                cnt++;
                sum += dist;
            }
        }
        System.out.println(String.format("%.2f",sum));
    }
    private static int find(int u,int[] parent) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u],parent);
    }
    private static void union(int u,int v,int[] parent) {
        int u1 = find(u,parent),v1 = find(v,parent);
        if(u1==v1) return;
        parent[u1] = v1;
    }
    private static class pp {
        double dist;
        int x,y;
        private pp(double dist,int x,int y) {
            this.dist = dist;
            this.x = x;
            this.y = y;
        }
    }
    private static class p {
        double x,y;
        private p(double x,double y) {
            this.x = x;
            this.y = y;
        }
    }
}