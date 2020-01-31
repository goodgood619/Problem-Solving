import java.io.*;
import java.util.HashMap;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        long n = Long.parseLong(input[0]);
        long p = Long.parseLong(input[1]);
        long q = Long.parseLong(input[2]);
        HashMap<Long,Long> dp = new HashMap<>();
        bw.write(go(n,p,q,dp)+" ");
        bw.flush();
        bw.close();
    }
    private static long go(long n,long p,long q,HashMap<Long,Long> dp) {
        if(n<=0) return 1;
        if(dp.get(n)!=null) return dp.get(n);
        long ret =  go(n/p,p,q,dp)+go(n/q,p,q,dp);
        dp.remove(n);
        dp.put(n,ret);
        return ret;
    }
}