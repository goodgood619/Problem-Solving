import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int cnt = 0;
        while (n >= 10) {
            String s = String.valueOf(n);
            int num = 1;
            for (int i = 0; i < s.length(); i++) num *= (s.charAt(i) - '0');
            n = num;
            cnt++;
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }
}