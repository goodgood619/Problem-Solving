import java.io.*;
import java.util.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-->0) {
            ans=0;
            StringTokenizer st= new StringTokenizer(br.readLine());
            int a =Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c= Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int ab = Integer.parseInt(st.nextToken()),bc = Integer.parseInt(st.nextToken()), ca = Integer.parseInt(st.nextToken());
            int first = Math.min(a,b), second = Math.min(a,c), third = Math.min(b,c);
            int[] arr = new int[3];
            arr[0] = first;
            arr[1] = second;
            dfs(0,0,arr,a,b,c,0,ab,bc,ca);
            bw.write(ans+"\n");
        }
        bw.flush();
        bw.close();
    }

    private static void dfs(int here,int cnt,int[] v,int a,int b,int c,int sum,int ab,int bc,int ca) {
        if (a < 0 || b < 0 || c < 0) return;
        if (cnt == 2) {
            sum += bc*Math.min(b, c);
            ans = Math.max(ans, sum);
            return;
        }
        int Max = v[here];
        for (int i = 0; i <= Max; i++) {
            // a,b
            if (here == 0) {
                dfs(here + 1, cnt + 1, v, a-i, b-i, c, sum + ab * i,ab,bc,ca);
            }
            // a,c
            else if (here == 1) {
                dfs(here + 1, cnt + 1, v, a-i, b, c-i, sum + ca * i,ab,bc,ca);
            }
        }
    }
}