import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for(int i=n;i>=1;i--) {
            StringBuilder sb = new StringBuilder();
            int rest = n-i;
            while(rest-- >0) bw.write(" ");
            for(int k=1;k<=i;k++) sb.append('*');
            bw.write(sb.toString()+"\n");
        }
        bw.flush();
        bw.close();
    }
}