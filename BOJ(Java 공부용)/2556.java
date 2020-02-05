import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int cnt = 1;
        int cnt2 = n - 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                bw.write("*");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}