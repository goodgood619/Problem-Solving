import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long x = Long.parseLong(st.nextToken()), y = Long.parseLong(st.nextToken());
        double rate = (double)y*100/x;
        if((long)rate>=99) {
            System.out.println(-1);
            return;
        }
        long left = 0, right = (long)1e11, ans = 0;
        while(left<=right) {
            long mid = (left + right) /2;
            double newrate = ((double)(y+mid)*100/(x+mid));
            if((long)newrate > (long)rate) {
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        System.out.println(left);
    }
}