import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        ArrayList<Integer> temp = new ArrayList<>();
        boolean[] visited = new boolean[n];
        go(0,n,temp,visited);
        bw.flush();
        bw.close();
    }
    private static void go(int cnt,int depth,ArrayList<Integer> temp,boolean[] visited) throws IOException {
        if(cnt == depth) {
            for(int i=0;i<temp.size();i++) {
                bw.write(temp.get(i)+" ");
            }
            bw.write("\n");
            return;
        }
        for(int i=0;i<depth;i++) {
            if(!visited[i]) {
                visited[i] = true;
                temp.add(i+1);
                go(cnt+1,depth,temp,visited);
                temp.remove(temp.size()-1);
                visited[i] = false;
            }
        }
    }
}