import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for(int i=0;i<n;i++) {
            for (int j= n-1; j>i; j--)
            {
                bw.write(" ");
            }
            for (int k = 0; k <= i; k++)
            {
                bw.write("*");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}