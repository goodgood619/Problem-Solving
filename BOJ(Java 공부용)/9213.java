import java.io.*;
import java.util.StringTokenizer;

import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] ssum = new int[1000001];
        for (int i = 2; i < 1000000; i++) {
            ssum[i]++;
            for (int j = i * 2; j <= 1000000; j += i) {
                if (j % i == 0) ssum[j] += i;
            }
        }
        int Case = 1;
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), stop = Integer.parseInt(st.nextToken()), bad = Integer.parseInt(st.nextToken());
            if (start == 0 && stop == 0 && bad == 0) break;
            int cnt = 0;
            for (int i = start; i <= stop; i++) {
                if (abs(ssum[i] - i) <= bad) cnt++;
            }
            bw.write("Test " + Case + ": " + cnt + "\n");
            Case++;
        }
        bw.flush();
        bw.close();
    }
}