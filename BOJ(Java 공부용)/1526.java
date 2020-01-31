import java.io.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        go(0,0,n);
        bw.write(ans+"\n");
        bw.flush();
        bw.close();
    }
    private static void go(int depth,int num,int n) {
        if(depth>=7) return;
        if(num<=n) {
            ans = max(ans,num);
        }
        go(depth+1,num*10+4,n);
        go(depth+1,num*10+7,n);
    }
}