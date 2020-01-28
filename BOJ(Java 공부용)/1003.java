import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int i=0;i<t;i++) {
            int n = Integer.parseInt(br.readLine().split(" ")[0]);
            int[] dp0 = new int[n+2];
            int[] dp1 = new int[n+2];
            for(int j=0;j<=n;j++) {
                dp0[j] = 0;
                dp1[j] = 0;
            }
            dp0[0] = 1;
            dp0[1] = 0;
            dp1[0] = 0;
            dp1[1] = 1;
            for(int j=2;j<=n;j++) {
                dp0[j] = dp0[j-1] +dp0[j-2];
                dp1[j] = dp1[j-1] +dp1[j-2];
            }
            bw.write(dp0[n] +" "+ dp1[n] +"\n");
        }
        bw.flush();
        bw.close();
    }
}