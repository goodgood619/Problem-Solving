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
        long x = Long.parseLong(input[3]);
        long y = Long.parseLong(input[4]);
        HashMap<Long,Long> dp = new HashMap<>();
        bw.write(go(n,p,q,x,y,dp)+" ");
        bw.flush();
        bw.close();
    }
    private static long go(long n,long p,long q,long x,long y,HashMap<Long,Long> dp) {
        if(n<=0) return 1;
        if(dp.get(n)!=null) return dp.get(n);
        long ret =  go(n/p-x,p,q,x,y,dp)+go(n/q-y,p,q,x,y,dp);
        dp.remove(n);
        dp.put(n,ret);
        return ret;
    }
}