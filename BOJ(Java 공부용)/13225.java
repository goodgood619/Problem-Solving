import java.io.*;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int t = Integer.parseInt(input[0]);
        for(int i=0;i<t;i++) {
            int n = Integer.parseInt(br.readLine());
            int cnt =0;
            for(int j = 1;j<=sqrt(n);j++) {
                if(n%j==0) {
                    if(j == n/j) cnt++;
                    else cnt+=2;
                }
            }
            System.out.println(n+" "+cnt);
        }
    }
}
