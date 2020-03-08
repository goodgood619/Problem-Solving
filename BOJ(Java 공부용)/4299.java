import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        double x = (a + b) / 2.0, y = (a - b) / 2.0;
        if (x != (int) x || y != (int) y || x < 0 || y < 0) bw.write("-1");
        else {
            int a1 = (int) x, a2 = (int) y;
            bw.write(a1 + " " + a2 + " ");
        }
        bw.flush();
        bw.close();
    }
}