import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= 2 * n - 1; i++) {
            StringBuilder sb = new StringBuilder();
            int rest = 0;
            int rest2 = 0;
            if (i <= n) {
                rest = n - i;
                rest2 = i;
            } else {
                rest2 = 2 * n - i;
                rest = n - rest2;
            }
            for (int j = 1; j <= n; j++) {
                if (rest2 != 0) {
                    sb.append('*');
                    rest2--;
                } else {
                    sb.append(' ');
                }
            }
            StringBuilder temp = new StringBuilder();
            temp.append(sb);
            temp.reverse();
            System.out.println(sb.toString()+temp.toString());
        }
    }
}