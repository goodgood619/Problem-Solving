import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] r = new int[n][m];
        int[][] g = new int[n][m];
        int[][] b = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                r[i][j] = Integer.parseInt(st.nextToken());
                g[i][j] = Integer.parseInt(st.nextToken());
                b[i][j] = Integer.parseInt(st.nextToken());
            }

        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int temp = 2126 * r[i][j] + 7152 * g[i][j] + 722 * b[i][j];
                if (temp < 510000) bw.write('#');
                else if (temp < 1020000) bw.write('o');
                else if (temp < 1530000) bw.write('+');
                else if (temp < 2040000) bw.write('-');
                else bw.write('.');
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

}