import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][3];
        int[] player = new int[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int j = 0; j < 3; j++) {
            boolean[] visited = new boolean[n];
            for (int i = 0; i < n; i++) {
                for (int k = i + 1; k < n; k++) {
                    if (arr[i][j] == arr[k][j]) {
                        visited[i] = true;
                        visited[k] = true;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    player[i] += arr[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            bw.write(player[i] + "\n");
        }
        bw.flush();
        bw.close();
    }
}