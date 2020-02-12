import java.io.*;
import java.util.StringTokenizer;
import static java.lang.StrictMath.abs;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        a--;
        b--;
        int y1 = a / 4;
        int x1 = a % 4;
        int y2 = b / 4;
        int x2 = b % 4;
        System.out.println(abs(y1 - y2) + abs(x1 - x2));
    }
}