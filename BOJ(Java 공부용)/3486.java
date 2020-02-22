import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            StringBuilder sb1 = new StringBuilder(st.nextToken()), sb2 = new StringBuilder(st.nextToken());
            sb1.reverse();
            sb2.reverse();
            int a = Integer.parseInt(sb1.toString()) + Integer.parseInt(sb2.toString());
            StringBuilder sb3 = new StringBuilder(String.valueOf(a));
            sb3.reverse();
            bw.write(Integer.parseInt(sb3.toString()) + "\n");
        }
        bw.flush();
        bw.close();
    }
}