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
        for(int i=1;i<=n;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        dp[0]= (int) -2e9;
        int en = 0;
        for(int i=1;i<=n;i++) {
            int idx = lowerbound(1,en+1,arr[i],dp);
            dp[idx] = arr[i];
            if(idx == en+1) en++;
        }
        System.out.println(en);
        
    }
    private static int lowerbound(int left,int right,int num,int[] dp) {
        while(left < right) {
            int mid = (left + right) / 2;
            if(dp[mid]<num) left = mid+1;
            else right = mid;
        }
        return right;
    }
}