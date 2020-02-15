import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());

        int[] a = new int[k + 1];
        int[] b = new int[k + 1];
        a[0] = 1;
        b[0] = 0;
        for (int i = 0; i < k; i++) {
            a[i + 1] = b[i];
            b[i + 1] = a[i] + b[i];
        }
        System.out.println(a[k] + " " + b[k]);
    }
}