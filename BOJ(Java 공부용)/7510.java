import java.io.*;
import java.util.Arrays;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int t = Integer.parseInt(input[0]);
        for(int i=0;i<t;i++) {
            String[] input2 = br.readLine().split(" ");
            int[] arr = new int[3];
            arr[0] = Integer.parseInt(input2[0]);
            arr[1] = Integer.parseInt(input2[1]);
            arr[2] = Integer.parseInt(input2[2]);
            Arrays.sort(arr);
            System.out.println("Scenario #"+(i+1)+":");
            if(arr[0]*arr[0]+arr[1]*arr[1] == arr[2]*arr[2]) {
                System.out.println("yes");
            }
            else System.out.println("no");
            System.out.println();
        }
    }
}
