import java.io.*;
import java.util.ArrayList;
import static java.lang.Math.abs;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<p> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            v.add(new p(Long.parseLong(input[0]),Long.parseLong(input[1])));
        }
        double plus = 0, minus = 0;
        for(int i=0;i<v.size();i++) {
            p a = v.get(i), b= v.get((i+1)%v.size());
            long temp = ccw(new p(0,0),a,b);
            if(temp > 0) {
                plus += ((double)temp/2);
            }
            else {
                minus += ((double)abs(temp)/2);
            }
        }
        System.out.println(String.format("%.1f",abs(plus-minus)));
    }
    private static long ccw(p a,p b,p c) {
        return (a.x*b.y+b.x*c.y+c.x*a.y) - (b.x*a.y+c.x*b.y+a.x*c.y);
    }
    private static class p {
        long x,y;
        private p(long x,long y) {
            this.x = x;
            this.y = y;
        }
    }
}