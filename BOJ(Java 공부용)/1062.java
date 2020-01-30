import java.io.*;
import java.util.ArrayList;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        ArrayList<String> v = new ArrayList<>();
        boolean[] visited = new boolean[26];
        for(int i=0;i<n;i++) {
            v.add(br.readLine());
        }
        if(k<5) {
            System.out.println("0");
        }
        else {
            k-=5;
            visited[0] = true;
            visited['n'-'a'] = true;
            visited['t'-'a'] = true;
            visited['i'-'a'] = true;
            visited['c'-'a'] = true;
            go(0,0,k,visited,v);
            bw.write(ans+"\n");
            bw.flush();
            bw.close();
        }
    }
    private static void go(int here,int cnt,int depth,boolean[] visited,ArrayList<String> v) {
        if(cnt == depth) {
            int temp = 0;
            for(int i=0;i<v.size();i++) {
                int no =0 ;
                for(int j=0;j<v.get(i).length();j++) {
                    char c = v.get(i).charAt(j);
                    if(visited[c-'a']) continue;
                    no = 1;
                    break;
                }
                if(no == 0) temp++;
            }
            ans = max(ans,temp);
            return;
        }
        for(int i=here;i<26;i++) {
            if(!visited[i]) {
                visited[i] = true;
                go(i+1,cnt+1,depth,visited,v);
                visited[i] = false;
            }
        }
    }
}