import java.io.*;

import static java.lang.Integer.max;

public class Main {
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String arr[] = br.readLine().split(" ");
        int n= Integer.parseInt(arr[0]),m = Integer.parseInt(arr[1]);
        boolean visited[] = new boolean[n];
        String[] s = br.readLine().split(" ");
        go(0,0,3,s,0,visited,m);
        bw.write(String.valueOf(ans));
        bw.flush();
    }

    private static void go(int idx,int cnt,int depth,String[] s,int total,boolean[] visited,int m) {
        if(cnt==depth) {
            if(total<=m) ans = max(ans,total);
            return;
        }
        for(int i=idx;i<s.length;i++) {
            int num = Integer.parseInt(s[i]);
            if(!visited[i]) {
                visited[i] =true;
                go(idx + 1, cnt + 1, depth, s, total + num,visited,m);
                visited[i] = false;
            }
        }
    }
}