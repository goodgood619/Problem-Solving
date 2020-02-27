import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
        int[][] board = new int[m + 1][m + 1];
        //(1,7)-> (7,10)으로 정답
        int sx = m, sy = 0, dir = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            int cnt = Integer.parseInt(st.nextToken());
            if (s.equals("TURN")) {
                if (cnt == 0) dir = left(dir);
                else dir = right(dir);
            } else {
                int p = cnt;
                while (sx + gox[dir] <= m && sx + gox[dir] >= 0 && sy + goy[dir] <= m && sy + goy[dir] >= 0 && p != 0) {
                    sx += gox[dir];
                    sy += goy[dir];
                    p--;
                }
                if (p > 0) {
                    System.out.println(-1);
                    return;
                }
            }
        }
        System.out.println(sy + " " + (m - sx));

    }

    private static int left(int dir) {
        return (dir + 3) % 4;
    }

    private static int right(int dir) {
        return (dir + 1) % 4;
    }
}