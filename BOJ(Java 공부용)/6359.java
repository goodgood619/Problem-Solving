import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            boolean[] visited = new boolean[n + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = i; j <= n; j += i) {
                    visited[j] = !visited[j];
                }
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (visited[i]) cnt++;
            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }
}