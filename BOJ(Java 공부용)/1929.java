import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[] notprime = new int[1000001];
        for(int i=1;i<=1000000;i++) notprime[i] = i;
        for(int i=2;i<=sqrt(1000000);i++) {
            if(notprime[i] == 1) continue;
            for(int j=i*i;j<=1000000;j+=i) {
                notprime[j] = 1;
            }
        }
        for(int i=m;i<=n;i++) {
            if(i==1) continue;
            if(notprime[i] == i) bw.write(notprime[i]+"\n");
        }
        bw.flush();
        bw.close();
    }
}