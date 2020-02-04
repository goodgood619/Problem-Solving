import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int h = 1;
        while(h<n) h<<=1;
        long[] seg = new long[h*2];
        for(int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            int what = Integer.parseInt(st.nextToken());
            if(what == 1) {
                int index = Integer.parseInt(st.nextToken());
                long value = Integer.parseInt(st.nextToken());
                update(index,value,seg,h);
            }
            else {
                int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
                if(left > right) {
                    int temp = left;
                    left = right;
                    right = temp;
                }
                bw.write(query(1,left,right,1,h,seg)+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
    private static void update(int index,long value,long[] seg,int h ) {
        index += h-1;
        seg[index] = value;
        while(index > 1) {
            index /= 2;
            seg[index] = seg[index*2] + seg[index*2+1];
        }
    }
    private static long query(int nodenum,int left,int right,int nodeleft,int noderight,long[] seg) {
        if(left > noderight || nodeleft > right) return 0;
        else if(left<=nodeleft && noderight <= right) return seg[nodenum];
        int mid = (nodeleft + noderight ) / 2;
        return query(nodenum*2,left,right,nodeleft,mid,seg) + query(nodenum*2+1,left,right,mid+1,noderight,seg);
    }
}