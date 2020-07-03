import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};
    static boolean ok = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), t = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()), p = Integer.parseInt(st.nextToken());
        n--;
        bw.write((n / t) * c * p + "");
        bw.flush();
        bw.close();
    }
}