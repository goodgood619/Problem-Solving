import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {2, 2, -1, -1, 1, 1, -2, -2};
    static int[] goy = {1, -1, 2, -2, 2, -2, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[][] visited = new boolean[6][6];
        boolean no = false;
        String s = br.readLine();
        int sx = 6 - (s.charAt(1) - '0'), sy = s.charAt(0) - 'A';
        int px = sx, py = sy;
        for (int i = 1; i < 36; i++) {
            s = br.readLine();
            int nx = 6 - (s.charAt(1) - '0'), ny = s.charAt(0) - 'A';
            if (nx < 0 || nx >= 6 || ny < 0 || ny >= 6 || visited[nx][ny]) {
                no = true;
                break;
            }
            boolean ok = false;
            for (int j = 0; j < 8; j++) {
                int tx = sx + gox[j], ty = sy + goy[j];
                if (tx == nx && ty == ny) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                no = true;
                break;
            }
            visited[nx][ny] = true;
            sx = nx;
            sy = ny;
        }
        boolean ok = false;
        for (int i = 0; i < 8; i++) {
            int nx = sx + gox[i], ny = sy + goy[i];
            if (nx == px && ny == py) {
                ok = true;
                break;
            }
        }
        System.out.println(!no && ok ? "Valid" : "Invalid");
    }
}