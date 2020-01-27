import java.io.*;
import java.util.Arrays;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int[] arr = new int[n];
        String[] input = br.readLine().split(" ");
        for(int i=0;i<input.length;i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(arr);
        int m = Integer.parseInt(br.readLine().split(" ")[0]);
        String[] input2 = br.readLine().split(" ");
        for(int i=0;i<input2.length;i++) {
            int num = Integer.parseInt(input2[i]);
            int left =0,right =n-1;
            boolean ok = false;
            while(left<=right) {
                int mid = (left+right)/2;
                if(arr[mid]<num) {
                    left = mid+1;
                }
                else if(arr[mid]>num) {
                    right = mid-1;
                }
                else {
                    ok = true;
                    break;
                }
            }
            bw.write(ok?"1\n":"0\n");
        }
        bw.flush();
    }
}