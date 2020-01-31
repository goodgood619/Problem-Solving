import java.io.*;
import java.util.Arrays;

import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        String[] input = br.readLine().split(" ");
        int[] arr = new int[n];
        int real = 0,max = 0;
        for(int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(input[i]);
            real += arr[i];
            max = max(max,arr[i]);
        }
        int m = Integer.parseInt(br.readLine().split(" ")[0]);
        Arrays.sort(arr);
        if(real <= m) System.out.println(max);
        else {
            int left = 0;
            int right = m-1;
            while(left<=right) {
                int sum = 0;
                int mid = (left+right) /2;
                for(int i=0;i<arr.length;i++) {
                    if(mid>arr[i]) sum += arr[i];
                    else sum += mid;
                }
                if(sum>m) right = mid -1;
                else left = mid+1;
            }
            left--;
            System.out.println(left);
        }
    }
}