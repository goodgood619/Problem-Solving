import java.io.*;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int min = (int)1e9;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s= br.readLine();
        int num = Integer.parseInt(s);
        boolean[] visited = new boolean[s.length()];
        StringBuilder sb = new StringBuilder();
        dfs(0,s.length(),sb,s,visited,num);
        bw.write(min==1e9?"0\n":min+"\n");
        bw.flush();
        bw.close();
    }
    private static void dfs(int cnt,int depth,StringBuilder sb, String s,boolean[] visited,int num) {
        if(cnt == depth) {
            int temp = Integer.parseInt(sb.toString());
            if(temp>num)
            min = min(min,temp);
            return;
        }
        for(int i=0;i<s.length();i++) {
            if(!visited[i]) {
                visited[i] = true;
                sb.append(s.charAt(i));
                dfs(cnt+1,depth,sb,s,visited,num);
                sb.deleteCharAt(sb.length()-1);
                visited[i] = false;
            }
        }
    }
}