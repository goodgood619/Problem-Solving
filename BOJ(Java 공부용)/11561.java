import java.io.*;
import static java.lang.Long.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int tc = 1; tc<=t ;tc++) {
            long n = Long.parseLong(br.readLine().split(" ")[0]);
            n *= 2;
            long left = 1, right = 1000000000, ans = 0;
            while(left<=right) {
                long mid = (left + right) / 2;
                long temp = (mid+1)*mid;
                if(temp > n ) right = mid-1;
                else {
                    ans = max(ans,mid);
                    left = mid + 1;
                }
            }
            bw.write(ans+"\n");
        }
        bw.flush();
        bw.close();
    }
}