import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int tc = 0 ;tc<t;tc++) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            int g = gcd(a,b);
            bw.write(a/g*b/g*g+" "+g+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static int gcd(int a,int b) {
        if(a%b==0) return b;
        return gcd(b%a,a);
    }
}