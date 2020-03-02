import java.io.*;
import java.util.Arrays;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        float[] v = new float[n];
        for (int i = 0; i < n; i++) {
            v[i] = Float.parseFloat(br.readLine());
        }
        Arrays.sort(v);
        for (int i = 0; i < 7; i++) bw.write(String.format("%.3f", v[i]) + "\n");
        bw.flush();
        bw.close();
    }
}