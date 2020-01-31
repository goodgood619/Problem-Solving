import java.io.*;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int[] notprime = new int[1001];
        notprime[1] = 1;
        for(int i=2;i<=sqrt(1000);i++) {
            if(notprime[i] == 1) continue;
            for(int j=i*i;j<=1000;j+=i) {
                notprime[j] = 1;
            }
        }
        String[] input = br.readLine().split(" ");
        int cnt = 0;
        for(int i=0;i<input.length;i++) {
            if(notprime[Integer.parseInt(input[i])]==0) cnt++;
        }
        bw.write(cnt+"\n");
        bw.flush();
        bw.close();
    }
}