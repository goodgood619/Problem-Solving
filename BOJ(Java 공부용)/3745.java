import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        while((s=br.readLine())!=null) {
            s = s.trim();
            int n = Integer.parseInt(s);
            int[] arr = new int[n+1];
            int[] dp = new int[n+1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=1;i<=n;i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            dp[0] = -98765;
            int en = 0;
            for(int i=1;i<=n;i++) {
                int idx = lowerbound(1,en+1,arr[i],dp);
                dp[idx] = arr[i];
                if(idx == en+1) en++;
            }
            bw.write(en+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static int lowerbound(int left,int right,int num,int[] dp) {
        while(left<right) {
            int mid = (left+right) /2;
            if(dp[mid]<num) left = mid + 1;
            else right = mid;
        }
        return right;
    }
}