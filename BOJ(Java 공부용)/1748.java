import java.io.*;
import java.util.ArrayList;
import static java.lang.Math.pow;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        ArrayList<Long> v = new ArrayList<>();
        long sum = 0;
        v.add((long) 1);
        for(int i=1;i<=s.length();i++) {
            v.add((long) pow(10,i-1));
        }
        for(int i=0;i<s.length();i++) {
            sum +=(s.charAt(i)-'0')*pow(10,s.length()-i-1);
        }
        long cnt = 0;
        for(int i=1;i<=s.length()-1;i++) {
            cnt += 9*pow(10,i-1)*i;
        }
        cnt += (sum-v.get(s.length())+1)*s.length();
        System.out.println(cnt);
    }
}
