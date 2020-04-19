import java.io.*;
import java.util.Arrays;

import static java.lang.Long.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        long m = Long.parseLong(input[1]);
        long[] arr = new long[n];
        long left =1, right = 0;
        for(int i=0;i<n;i++) {
            String input2 = br.readLine();
            arr[i] = Long.parseLong(input2);
            right = max(right,arr[i]);
        }

        while(left<=right) {
            long mid = (left+right)/2 ;
            long cnt = 0;
            for(int i=0;i<arr.length;i++) {
                cnt += (arr[i]/mid);
            }
            if(cnt<m) right = mid-1;
            else left = mid+1;
        }
        left--;
        bw.write(String.valueOf(left)+"\n");
        bw.flush();
        bw.close();
    }
}