import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for(int i=1;i<n;i++) {

            int rest = n-i;
            while(rest-- >0) bw.write(" ");
            for(int k=1;k<=2*i-1;k++) bw.write('*');
            bw.write("\n");
        }
        for(int i=1;i<=2*n-1;i++) {
            bw.write('*');
        }
        bw.write("\n");
        for (int i = n-1; i>=1; i--){
            int rest = n-i;
            while(rest-- >0) bw.write(" ");
            for (int k = 1; k <= 2 * i - 1; k++) {
               bw.write('*');
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}