import java.io.*;
import java.util.*;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] notprime = new int[10001];
        for(int i=2;i<=sqrt(10000);i++) {
            if(notprime[i] == 1) continue;
            for(int j=i*i;j<=10000;j+=i) {
                notprime[j] = 1;
            }
        }
        ArrayList<Integer> v = new ArrayList<>();
        for(int i=2;i<10000;i++)  {
            if(notprime[i] ==0 ) v.add(i);
        }
        int t= Integer.parseInt(st.nextToken());
        for(int tc = 0 ;tc<t;tc++) {
            st = new StringTokenizer(br.readLine());
            int n= Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
            int ans = bfs(n,m,v);
            bw.write(ans==-1?"Impossible":ans+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static int bfs(int st,int en,ArrayList<Integer> v) {
        boolean[] visited =new boolean[10001];
        visited[st] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(st,0));
        int temp =-1;
        while(!q.isEmpty()) {
            int num = q.peek().num;
            int cnt = q.peek().cnt;
            q.poll();
            if(num == en) {
                temp = cnt;
                break;
            }
            StringBuilder sb = new StringBuilder();
            sb.append(num);
            for(int i=0;i<sb.length();i++) {
                char c = sb.charAt(i);
                for(int j=0;j<10;j++) {
                    if(c == j+'0') continue;
                    StringBuilder ssb = new StringBuilder();
                    ssb.append(num);
                    ssb.setCharAt(i, (char) (j+'0'));
                    int newnum = Integer.parseInt(ssb.toString());
                    int idx = lowerbound(0,v.size(),newnum,v);
                    if(idx == v.size()) continue;
                    if(v.get(idx) == newnum && !visited[newnum]  && newnum>=1000 && newnum<10000) {
                        q.add(new p(newnum,cnt+1));
                        visited[newnum] = true;
                    }
                }
            }
        }
        return temp;
    }
    private static class p {
        int num,cnt;
        private p(int num,int cnt) {
            this.num =num;
            this.cnt = cnt;
        }
    }
    private static int lowerbound(int left, int right, int num, ArrayList<Integer> v) {
        while(left <right) {
            int mid = (left+right) /2 ;
            if(v.get(mid) < num) left = mid+1;
            else right = mid;
        }
        return right;
    }
}