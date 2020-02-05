import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        p[] arr = new p[n];
        for(int i=0;i<n;i++) arr[i] =  new p(0,0);
        int[] dp = new int[n+1];
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken());
            arr[i].first = first;
            arr[i].second = second;
        }
        Arrays.sort(arr, (a, b) -> {
            if(a.first<b.first) return -1;
            else if(a.first>b.first) return 1;
            else {
                if(a.second <b.second) return -1;
                else if(a.second > b.second) return 1;
                else return 0;
            }
        });
        dp[0] =-98765;
        int en = 0;
        for(int i=0;i<n;i++) {
            int idx = lowerbound(1,en+1,arr[i].second,dp);
            dp[idx] = arr[i].second;
            if(idx == en+1) en++;
        }
        System.out.println(n-en);
    }
    private static class p {
        int first,second;
        private p(int first,int second) {
            this.first = first;
            this.second = second;
        }
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