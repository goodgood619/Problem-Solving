import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) break;
            String[] input = new String[n];
            for (int i = 0; i < n; i++) {
                String s = br.readLine();
                input[i] = s;
            }
            Arrays.sort(input, Comparator.comparing(String::toLowerCase));
            bw.write(input[0] + "\n");

        }
        bw.flush();
        bw.close();
    }
}