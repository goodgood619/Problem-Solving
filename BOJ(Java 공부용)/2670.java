import java.io.*;
import static java.lang.StrictMath.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) arr[i] = Double.parseDouble(br.readLine());
        double max = 0;
        for (int i = 0; i < n; i++) {
            double gob = arr[i];
            for (int j = i + 1; j < n; j++) {
                max = max(max, gob);
                gob *= arr[j];
            }
        }

        System.out.println(String.format("%.3f", max));
    }
}