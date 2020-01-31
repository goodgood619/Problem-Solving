import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] check = new boolean[400001];
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        String[] input = br.readLine().split(" ");
        int[] arr = new int[n];
        int cnt = 0;
        for(int i=0;i<input.length;i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(check[arr[i]-arr[j]+200000]) {
                    cnt++;
                    break;
                }
            }
            for(int j=0;j<=i;j++) check[arr[i]+arr[j]+200000] = true;
        }
        System.out.println(cnt);
     }
}