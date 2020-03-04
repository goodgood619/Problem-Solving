import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1, 1, 1, -1, -1};
    static int[] goy = {1, -1, 0, 0, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int l = Integer.parseInt(br.readLine()), n = Integer.parseInt(br.readLine());
        int Max = 0, expect = 0;
        int[] roll = new int[1001];
        int[] who = new int[n + 1];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken());
            if (Max < second - first) {
                Max = second - first;
                expect = i + 1;
            }
            for (int j = first; j <= second; j++) {
                if (roll[j] != 0) continue;
                roll[j] = i + 1;
            }
        }

        for (int i = 1; i <= 1000; i++) {
            who[roll[i]]++;
        }
        Max = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (Max < who[i]) {
                Max = who[i];
                ans = i;
            }
        }
        bw.write(expect + "\n" + ans + "\n");
        bw.flush();
        bw.close();
    }
}