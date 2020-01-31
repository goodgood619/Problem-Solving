import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int z=0;z<tc;z++) {
            String[] input = br.readLine().split(" ");
            long sx = Long.parseLong(input[0]);
            long sy = Long.parseLong(input[1]);
            long ex = Long.parseLong(input[2]);
            long ey = Long.parseLong(input[3]);
            int ans = 0;
            int n = Integer.parseInt(br.readLine().split(" ")[0]);
            for(int i=0;i<n;i++) {
                String[] input2 = br.readLine().split(" ");
                long x = Long.parseLong(input2[0]);
                long y = Long.parseLong(input2[1]);
                long r = Long.parseLong(input2[2]);
                long dist1 = (x-sx)*(x-sx)+(y-sy)*(y-sy);
                long dist2 = (x-ex)*(x-ex)+(y-ey)*(y-ey);
                long dist3 = r*r;
                if((dist1-dist3)*(dist2-dist3)<=0) ans++;
            }
            bw.write(ans+"\n");
        }
        bw.flush();
        bw.close();
     }
}