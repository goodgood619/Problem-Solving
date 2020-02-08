import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Math.pow;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String s = st.nextToken();
        int num = Integer.parseInt(st.nextToken()), sum = 0;
        for (int i = s.length() - 1, j = 0; i >= 0; i--, j++) {
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                sum += (s.charAt(i) - 55) * pow(num, j);
            } else {
                sum += (s.charAt(i) - '0') * pow(num, j);
            }
        }
        System.out.println(sum);
    }
}