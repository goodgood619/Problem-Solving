import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int[] arr = new int[n];
        for(int i=0;i<arr.length;i++) {
            arr[i] = i+1;
        }
        for(int i=0;i<m;i++) {
            String[] input2 = br.readLine().split(" ");
            int left = Integer.parseInt(input2[0]);
            int right = Integer.parseInt(input2[1]);
            left--;
            right--;
            for(int j=left,k=right;j<k;j++,k--) {
                int temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
        for(int item : arr) {
            bw.write(String.valueOf(item)+" ");
        }
        bw.flush();
        bw.close();
    }
}
