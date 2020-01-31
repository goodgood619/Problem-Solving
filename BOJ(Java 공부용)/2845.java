import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int l = Integer.parseInt(input[0]);
        int p = Integer.parseInt(input[1]);
        int a = l*p;
        int[] arr = new int[5];
        String[] input2 = br.readLine().split(" ");
        for(int i=0;i<5;i++) {
            arr[i] = Integer.parseInt(input2[i])-a;
        }
        for(int i=0;i<5;i++) {
            bw.write(arr[i]+" ");
        }
        bw.flush();
        bw.close();
    }
}