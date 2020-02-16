import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int f = Integer.parseInt(br.readLine());
        n = n - n % 100;
        for (int i = n; i < n + 100; i++) {
            if (i % f == 0) {
                int rest = i - n;
                if (rest < 10) System.out.println("0" + rest);
                else System.out.println(rest);
                return;
            }
        }
    }
}