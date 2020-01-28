import java.io.*;
import java.util.Arrays;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int[] a = new int[n];
        int[] b= new int[n];
        String[] input = br.readLine().split(" ");
        String[] input2 = br.readLine().split(" ");
        for(int i=0;i<input.length;i++) {
            a[i] = Integer.parseInt(input[i]);
            b[i] = Integer.parseInt(input2[i]);
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int sum = 0;
        for(int i=0,j=n-1;i<n;i++,j--) {
            sum += a[i]*b[j];
        }
        bw.write(sum+"\n");
        bw.flush();
        bw.close();
    }
}