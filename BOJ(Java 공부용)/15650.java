import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]),m = Integer.parseInt(input[1]);
        ArrayList<Integer> v = new ArrayList<>();
        boolean[] visited = new boolean[n];
        for(int i=1;i<=n;i++) {
            v.add(i);
        }

        go(0,0,m,v,visited);
    }
    private static void go(int index, int cnt, int depth, ArrayList<Integer> v, boolean[] visited) throws IOException {
        if(cnt == depth) {
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=0;i<visited.length;i++) {
                if(visited[i]) {
                    temp.add(i+1);
                }
            }
            for(int i=0;i<temp.size();i++) {
                bw.write(String.valueOf(temp.get(i))+" ");
            }
            bw.write("\n");
            bw.flush();
            return;
        }

        for(int i=index;i<v.size();i++) {
            if(!visited[i]) {
                visited[i] =true;
                go(i+1,cnt+1,depth,v,visited);
                visited[i] =false;
            }
        }
    }

}