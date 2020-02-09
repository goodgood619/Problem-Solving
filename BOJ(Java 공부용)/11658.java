import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] arr = new int[n + 1][n + 1];
        int[][] fenwick = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                update(fenwick, i, j, arr[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            if (a == 0) {
                int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()), value = Integer.parseInt(st.nextToken());
                int diff = value - arr[x][y];
                arr[x][y] = value;
                update(fenwick, x, y, diff);
            } else {
                int x1 = Integer.parseInt(st.nextToken()), y1 = Integer.parseInt(st.nextToken()), x2 = Integer.parseInt(st.nextToken()), y2 = Integer.parseInt(st.nextToken());
                bw.write((query(fenwick, x2, y2) - query(fenwick, x1 - 1, y2) - query(fenwick, x2, y1 - 1) + query(fenwick, x1 - 1, y1 - 1)) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }

    private static int query(int[][] fenwick, int i, int j) {
        int sum = 0, temp;
        while (i > 0) {
            temp = j;
            while (temp > 0) {
                sum += fenwick[i][temp];
                temp -= (temp & -temp);
            }
            i -= (i & -i);
        }
        return sum;
    }

    private static void update(int[][] fenwick, int i, int j, int value) {
        int temp;
        while (i <= fenwick.length) {
            temp = j;
            while (temp <= fenwick[i].length) {
                fenwick[i][temp] += value;
                temp += (temp & -temp);
            }
            i += (i & -i);
        }
    }
}