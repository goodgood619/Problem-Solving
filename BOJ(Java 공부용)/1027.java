import java.io.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        long[] height = new long[n];
        int[] cnt = new int[n];
        String[] input = br.readLine().split(" ");
        for(int i=0;i<input.length;i++) {
            height[i] = Long.parseLong(input[i]);
        }
        double Max = -1e10;
        for(int i=0;i<n;i++) {
            Max = -1e10;
            for(int j=i+1;j<n;j++) {
                double d = (double)(height[j]-height[i])/(j-i);
                if(Max<d) {
                    Max = d;
                    cnt[i]++;
                    cnt[j]++;
                }
            }
        }
        int max = 0;
        for(int i=0;i<n;i++) {
            max = max(max,cnt[i]);
        }
        bw.write(max+"\n");
        bw.flush();
        bw.close();
    }
}