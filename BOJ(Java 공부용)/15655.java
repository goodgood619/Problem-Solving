import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        String[] input2 = br.readLine().split(" ");
        ArrayList<Integer> v = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        boolean[] visited = new boolean[n];
        for(int i=0;i<input2.length;i++) {
            v.add(Integer.parseInt(input2[i]));
        }
        Collections.sort(v);
        go(0,0,m,v,visited,temp);
        bw.flush();
        bw.close();
    }
    private static void go(int here,int cnt,int depth,ArrayList<Integer> v,boolean[] visited,ArrayList<Integer> temp) throws IOException {
        if(cnt == depth) {
            for(int i=0;i<temp.size();i++) {
                bw.write(temp.get(i)+" ");
            }
            bw.write("\n");
            return;
        }
        for(int i=here;i<v.size();i++) {
            if (!visited[i]) {
                temp.add(v.get(i));
                visited[i] = true;
                go( i+1,cnt + 1, depth, v,visited,temp);
                temp.remove(temp.size() - 1);
                visited[i] = false;
            }
        }
    }
}
