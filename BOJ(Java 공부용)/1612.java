import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n % 2 == 0) System.out.println(-1);
        else {
            int k = 0;
            for (int i = 1; i <= n; i++) {
                k = (k * 10 + 1) % n;
                if (k == 0) {
                    System.out.println(i);
                    return;
                }
            }
            System.out.println(-1);
        }
    }
}