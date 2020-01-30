import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        go(0,0,input[1].length(),a,b);
        System.out.println(ans);
    }
    private static void go(long sum,int cnt,int depth,int a,int b) {
        if(cnt > depth) {
            return;
        }
        if(sum>=a && sum<=b) ans++;
        go(sum*10+4,cnt+1,depth,a,b);
        go(sum*10+7,cnt+1,depth,a,b);
    }
}