import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[]gox = {0,1,-1,0};
    static int[]goy = {1,0,0,-1};
    static double win = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String[] input = br.readLine().split(" ");
            int first = Integer.parseInt(input[0]);
            int d = Integer.parseInt(input[1]);
            int end = Integer.parseInt(input[2]);
            if(first == 0 && d ==0 && end ==0 ) break;
            double ans = (double)(end-first)/d;
            if(ans-(int)ans != 0) {
                bw.write("X\n");
            }
            else {
                ans++;
                int a = (int)ans;
                bw.write(String.valueOf(a)+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
}