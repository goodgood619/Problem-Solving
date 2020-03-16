import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static double win = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken()), third = Integer.parseInt(st.nextToken());
            if (first == 0 && second == 0 && third == 0) break;
            third -= first;
            if (third / second >= 0 && third / second == (third * 1.0) / second) {
                bw.write(((third / second) + 1) + "\n");
            } else bw.write("X\n");
        }
        bw.flush();
        bw.close();
    }
}