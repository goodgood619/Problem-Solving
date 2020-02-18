import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int d = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[] a = new int[d + 1];
        int[] b = new int[d + 1];
        a[1] = 1;
        a[2] = 0;
        b[1] = 0;
        b[2] = 1;
        for (int i = 3; i <= d; i++) {
            a[i] = a[i - 1] + a[i - 2];
            b[i] = b[i - 1] + b[i - 2];
        }

        int x = a[d], y = b[d];
        for (int i = 1; ; i++) {
            for (int j = 1; ; j++) {
                if (i * x + j * y == k) {
                    bw.write(i + "\n" + j + "\n");
                    bw.flush();
                    bw.close();
                    return;
                } else if (i * x + j * y > k) break;
            }
        }
    }

}