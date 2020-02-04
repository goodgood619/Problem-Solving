import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long[] a = new long[n];
        long[] b = new long[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) {
            a[i] = Long.parseLong(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) {
            b[i] = Long.parseLong(st.nextToken());
        }
        for(int i=0;i<n;i++) {
            long ans = upperbound(i,b.length,b,a[i]) - (i+1);
            bw.write(ans + " ");
        }
        bw.flush();
        bw.close();
    }
    private static long upperbound(int left,int right,long[] v ,long num) {
        while(left < right) {
            int mid = (left + right) / 2;
            if(v[mid]<=num) left = mid+1;
            else right = mid;
        }
        return right;
    }
}