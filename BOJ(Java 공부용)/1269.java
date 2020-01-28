import java.io.*;
import java.util.Arrays;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int[] a = new int[n];
        int[] b = new int[m];
        String[] input2 = br.readLine().split(" ");
        String[] input3 = br.readLine().split(" ");
        for(int i=0;i<n;i++) {
            a[i] = Integer.parseInt(input2[i]);
        }
        for(int i=0;i<m;i++) {
            b[i] = Integer.parseInt(input3[i]);
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int total = n + m;
        for(int i=0;i<n;i++) {
            int left = 0, right = m-1;
            boolean ok = false;
            while(left<=right) {
                int mid = (left+ right) / 2;
                if(a[i]<b[mid]) right = mid - 1;
                else if(a[i]>b[mid]) left = mid+1;
                else {
                    ok = true;
                    break;
                }
            }
            if(ok) total-=2;
        }
        bw.write(total+"\n");
        bw.flush();
        bw.close();
    }
}