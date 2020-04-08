import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n= Integer.parseInt(br.readLine());
        StringTokenizer st= new StringTokenizer(br.readLine());
        double a = Double.parseDouble(st.nextToken());
        double b=0;
        for(int i=1;i<n;i++) {
            b += Double.parseDouble(st.nextToken());
        }
        int j = Integer.parseInt(br.readLine()), c = Integer.parseInt(br.readLine());
        for(int i=1;i<=c;i++) {
            double ta = a+j*a/(a+b);
            double tb = b+j*b/(a+b);
            a = ta;
            b =tb;
        }
        System.out.print(String.format("%.9f", a));
    }
}