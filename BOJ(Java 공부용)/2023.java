import java.io.*;
import static java.lang.Math.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        go(0,n,sb);
        bw.flush();
        bw.close();
    }
    private static void go(int cnt,int depth,StringBuilder sb) throws IOException {
        if(cnt == depth) {
            if(check(sb)) return;
            bw.write(sb.toString()+"\n");
            return;
        }
        if(sb.length()>=1 && check(sb)) return;
        for(int i=0;i<10;i++) {
            sb.append(i);
            go(cnt+1,depth,sb);
            sb.deleteCharAt(sb.length()-1);
        }
    }
    private static boolean check(StringBuilder sb) {
        int num = Integer.parseInt(sb.toString());
        if(num ==0 || num == 1) return true;
        for(int i=2;i<=sqrt(num);i++) {
            if(num%i ==0) return true;
        }
        return false;
    }
}