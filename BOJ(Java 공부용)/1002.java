import java.io.*;

import static java.lang.Math.abs;
import static java.lang.Math.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int i=0;i<t;i++) {
            String[] input = br.readLine().split(" ");
            double x1 = Double.parseDouble(input[0]);
            double y1 = Double.parseDouble(input[1]);
            double r1 = Double.parseDouble(input[2]);
            double x2 = Double.parseDouble(input[3]);
            double y2 = Double.parseDouble(input[4]);
            double r2 = Double.parseDouble(input[5]);
            double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            if(x1 == x2 && y1 == y2) {
                if(r1 == r2) bw.write("-1\n");
                else bw.write("0\n");
            }
            else {
                if(abs(r1-r2)<d && d < abs(r1+r2)) bw.write("2\n");
                else if(d == abs(r1-r2) || d == abs(r1+r2)) bw.write("1\n");
                else bw.write("0\n");
            }
        }
        bw.flush();
        bw.close();
    }
}