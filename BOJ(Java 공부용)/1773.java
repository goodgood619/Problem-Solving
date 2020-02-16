import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
        boolean[] visited = new boolean[c + 1];
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            for (int j = num; j <= c; j += num) {
                if (!visited[j]) {
                    visited[j] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= c; i++) {
            if (visited[i]) cnt++;
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }
}