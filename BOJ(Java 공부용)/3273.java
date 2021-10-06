import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        boolean[] visited = new boolean[2000001];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            visited[num] = true;
            arr[i] = num;
        }
        int x = Integer.parseInt(br.readLine()), cnt = 0;
        for (int i = 0; i < n; i++) {
            int rest = x - arr[i];
            if (rest <= 0 || !visited[rest]) continue;
            cnt++;
        }
        cnt /= 2;
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }
}