import java.io.*;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int[] notprime = new int[1004000];
        notprime[1] = 1;
        for(int i=2;i<=sqrt(1004000);i++) {
            for(int j=i*i;j<1004000;j+=i) {
                notprime[j] = 1;
            }
        }
        boolean ok = false;
        for(int i=n;;i++) {
            if(notprime[i] != 0) continue;
            String s = String.valueOf(i);
            int temp = 0;
            for(int j=0,k=s.length()-1;j<=k;j++,k--) {
                if(s.charAt(j) != s.charAt(k)) {
                    temp++;
                    break;
                }
             }
            if(temp == 0) {
                ok = true;
            }
            if(ok) {
                System.out.println(i);
                return;
            }
        }
    }
}