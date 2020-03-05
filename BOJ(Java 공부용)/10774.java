import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1, 1, 1, -1, -1};
    static int[] goy = {1, -1, 0, 0, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int j = Integer.parseInt(br.readLine()), a = Integer.parseInt(br.readLine());
        int[] uniform = new int[j + 1];
        boolean[] visited = new boolean[j + 1];
        for (int i = 1; i <= j; i++) {
            String s = br.readLine();
            if (s.equals("S")) uniform[i] = 0;
            else if (s.equals("M")) uniform[i] = 1;
            else uniform[i] = 2;
        }
        int cnt = 0;
        for (int i = 0; i < a; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            int num = Integer.parseInt(st.nextToken());
            if (s.equals("S")) {
                if (uniform[num] >= 0 && !visited[num]) {
                    visited[num] = true;
                    cnt++;
                }
            } else if (s.equals("M")) {
                if (uniform[num] >= 1 && !visited[num]) {
                    visited[num] = true;
                    cnt++;
                }
            } else {
                if (uniform[num] >= 2 && !visited[num]) {
                    visited[num] = true;
                    cnt++;
                }
            }
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();

    }
}