import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] goy = {-1,0,1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] notprime = new int[40001];
        int[] dp = new int[40001];
        for(int i=2;i<=sqrt(40000);i++) {
            if(notprime[i] == 1) continue;
            for(int j = i*i ;j<=40000;j+=i) {
                notprime[j] = 1;
            }
        }
        ArrayList<Integer> v = new ArrayList<>();
        for(int i=2;i<=40000;i++) {
            if(notprime[i] == 0) v.add(i);
        }
        dp[0] = 1;
        for(int j=0;j<v.size();j++) {
            for(int i=2;i<=n;i++) {
                if(i-v.get(j)>=0) {
                    dp[i] += dp[i-v.get(j)];
                    dp[i] %= 123456789;
                }
            }
        }
        System.out.println(dp[n]%123456789);
    }
}