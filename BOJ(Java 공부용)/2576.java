import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = 7;
        int sum = 0, Min = 101;
        while(t-- >0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            if (a % 2 == 1) {
                sum += a;
                Min = min(a, Min);
            }
            else continue;
        }
        if (sum == 0) bw.write("-1\n");
        else {
            bw.write(sum+"\n");
            bw.write(Min+"\n");
        }
        bw.flush();
        bw.close();
    }
}