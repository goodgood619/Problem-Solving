import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[][] arr = new int[n+1][5];
        for(int i=1;i<=n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=4;j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[] v1 = new int[n*n];
        int[] v2 = new int[n*n];
        int idx = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                int k = 1, p = 2;
                v1[idx] = arr[i][k] + arr[j][p];
                v2[idx] = arr[i][k+2] + arr[j][p+2];
                idx++;
            }
        }

        Arrays.sort(v1);
        Arrays.sort(v2);
        long cnt = 0;
        for(int i=0;i<v1.length;i++) {
            long a = lowerbound(0,v2.length,v2,-v1[i]);
            long b= upperbound(0,v2.length,v2,-v1[i]);
            cnt += (b-a);
        }
        System.out.println(cnt);
    }
    private static long lowerbound(int left,int right,int[] v, int num) {
        while(left < right) {
            int mid = (left + right) / 2;
            if(v[mid]<num) left = mid+1;
            else right = mid;
        }
        return right;
    }
    private static long upperbound(int left,int right,int[] v ,int num) {
        while(left < right) {
            int mid = (left + right) / 2;
            if(v[mid]<=num) left = mid+1;
            else right = mid;
        }
        return right;
    }
}