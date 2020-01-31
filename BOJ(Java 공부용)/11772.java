import java.io.*;
import static java.lang.Math.pow;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0,1,1,-1,-1};
    static int[] goy = {1,0,0,-1,1,-1,1,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        long sum = 0;
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            int length = s.length();
            long temp = 0;
            for(int j=0;j<length-1;j++) {
                temp += (s.charAt(j)-'0')*pow(10,length-2-j);
            }
            int gob = s.charAt(length-1)-'0';
            if(gob ==0) temp = 1;
            long p = temp;
            for(int j=1;j<gob;j++) {
                temp *= p;
            }
            sum += temp;
        }
        System.out.println(sum);
    }
}