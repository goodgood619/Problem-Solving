import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int l = Integer.parseInt(input[0]), c = Integer.parseInt(input[1]);
        String[] input2 = br.readLine().split(" ");
        ArrayList<Character> v = new ArrayList<>();
        boolean[] visited = new boolean[17];
        for(int i=0;i<input2.length;i++) {
            v.add(input2[i].charAt(0));
        }
        Collections.sort(v);
        StringBuilder s = new StringBuilder();
        dfs(0,0,0,0,l,s,visited,v);
        bw.flush();
        bw.close();
    }
    private static void dfs(int here,int mo,int ja,int cnt,int depth,StringBuilder s,boolean[] visited,ArrayList<Character> v) throws IOException {
        if(cnt == depth) {
            if(mo>=1 && ja>=2) {
                bw.write(s.toString() + "\n");
            }
            return;
        }
        for(int i=here;i<v.size();i++) {
            if(!visited[i]) {
                visited[i] = true;
                if(v.get(i) == 'a' || v.get(i)=='e' || v.get(i)=='i' || v.get(i)=='o' || v.get(i)=='u')
                    dfs(i+1,mo+1,ja,cnt+1,depth,s.append(v.get(i)),visited,v);
                else dfs(i+1,mo,ja+1,cnt+1,depth,s.append(v.get(i)),visited,v);
                s.deleteCharAt(s.length()-1);
                visited[i] = false;
            }
        }
    }
}