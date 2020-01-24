import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int k = Integer.parseInt(input[2]);
        int h=1;
        while(h<n) h<<=1;
        long[] v = new long[h*2];
        for(int i=0;i<v.length;i++) {
            v[i] = 0;
        }
        for(int i=1;i<=n;i++) {
            String[] input1 = br.readLine().split(" ");
            Long num = Long.parseLong(input1[0]);
            update(i,num,h,v);
        }
        for(int i=0;i<m+k;i++) {
            String[] input2 = br.readLine().split(" ");
            int a = Integer.parseInt(input2[0]);
            int b = Integer.parseInt(input2[1]);
            Long c = Long.parseLong(input2[2]);
            if(a == 1) {
                update(b,c,h,v);
            }else {
                Long ans = query(1,b,c.intValue(),1,h,v);
                bw.write(String.valueOf(ans)+"\n");
            }
        }
        bw.flush();
    }
    private static void update(int index,long value,int h,long[] v) {
        index +=h-1;
        v[index] = value;
        while(index>1) {
            index/=2;
            v[index] = v[index*2]+v[index*2+1];
        }
    }
    private static long query(int nodenum, int left,int right,int nodeleft,int noderight,long[] v) {
        if(nodeleft>right || left>noderight) return 0;
        else if(left<=nodeleft && noderight <= right) return v[nodenum];
        int mid = (nodeleft+noderight) /2 ;
        return query(nodenum*2,left,right,nodeleft,mid,v) +query(nodenum*2+1,left,right,mid+1,noderight,v);
    }
}
