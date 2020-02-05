import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n+1];
        int[] dp = new int[n+1];
        int[] path = new int[n+1];
        boolean[] check = new boolean[n+1];
        for(int i=1;i<=n;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        dp[0]= (int) -2e9;
        int en = 0;
        for(int i=1;i<=n;i++) {
            int idx = lowerbound(1,en+1,arr[i],dp);
            dp[idx] = arr[i];
            path[i] = idx;
            if(idx == en+1) en++;
        }
        System.out.println(en);
        go(en,n,path,check);
        for(int i=1;i<=n;i++) {
            if(check[i]) bw.write(arr[i]+" ");
        }
        bw.flush();
        bw.close();
    }
    private static int lowerbound(int left,int right,int num,int[] dp) {
        while(left < right) {
            int mid = (left + right) / 2;
            if(dp[mid]<num) left = mid+1;
            else right = mid;
        }
        return right;
    }
    private static void go(int en,int n,int[] path,boolean[] check) {
        if (n <= 0) return;
        if (path[n] == en) {
            go(en - 1, n - 1,path,check);
            check[n] = true;
        }
        else go(en, n - 1,path,check);
    }
}