import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        ArrayList<Integer> v = new ArrayList<>();
        boolean[] visited = new boolean[n];
        go(0,0,n,m,v,visited);
        bw.flush();
        bw.close();
    }
    private static void go(int here,int cnt,int n,int depth,ArrayList<Integer> v,boolean[] visited) throws IOException {
        if(cnt == depth) {
            for(int i=0;i<v.size();i++) {
                bw.write(v.get(i)+" ");
            }
            bw.write("\n");
            return;
        }
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                visited[i] = true;
                v.add(i+1);
                go(here+1,cnt+1,n,depth,v,visited);
                v.remove(v.size()-1);
                visited[i] = false;
            }
        }
    }
}