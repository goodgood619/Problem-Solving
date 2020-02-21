import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int robotcnt = Integer.parseInt(st.nextToken()), order = Integer.parseInt(st.nextToken());
        ArrayList<p> robot = new ArrayList<>();
        for (int i = 1; i <= robotcnt; i++) {
            st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
            char dir = st.nextToken().charAt(0);
            y--;
            x = n - x;
            robot.add(new p(x, y, dir));
        }
        for (int i = 0; i < order; i++) {
            st = new StringTokenizer(br.readLine());
            int who = Integer.parseInt(st.nextToken());
            char what = st.nextToken().charAt(0);
            int cnt = Integer.parseInt(st.nextToken());
            who--;
            int x = robot.get(who).x, y = robot.get(who).y;
            char dir = robot.get(who).dir;
            int idx = -1;
            if (dir == 'E') idx = 0;
            if (dir == 'S') idx = 1;
            if (dir == 'W') idx = 2;
            if (dir == 'N') idx = 3;

            if (what == 'L') {
                int rest = cnt;
                while (rest != 0) {
                    idx = (idx + 3) % 4;
                    dir = direction(idx);
                    rest--;
                }
                robot.set(who, new p(x, y, dir));
            } else if (what == 'R') {
                int rest = cnt;
                while (rest != 0) {
                    idx = (idx + 1) % 4;
                    dir = direction(idx);
                    rest--;
                }
                robot.set(who, new p(x, y, dir));
            } else {
                int rest = cnt, res1 = 0;
                while (rest != 0) {
                    int nx = x + gox[idx], ny = y + goy[idx];
                    int res = check(who, nx, ny, n, m, robot);
                    if (res == 0) {
                        rest--;
                        x = nx;
                        y = ny;
                        continue;
                    }
                    x = nx;
                    y = ny;
                    res1 = res;
                    break;
                }
                if (res1 == 1) {
                    System.out.println("Robot " + (who + 1) + " crashes into the wall");
                    return;
                }
                if (res1 == 2) {
                    for (int j = 0; j < robot.size(); j++) {
                        if (x == robot.get(j).x && y == robot.get(j).y) {
                            System.out.println("Robot " + (who + 1) + " crashes into robot " + (j + 1));
                            return;
                        }
                    }
                }
                robot.set(who, new p(x, y, dir));
            }
        }
        System.out.println("OK");
    }

    private static int check(int index, int x, int y, int n, int m, ArrayList<p> robot) {
        if (x < 0 || x >= n || y < 0 || y >= m) return 1;
        for (int i = 0; i < robot.size(); i++) {
            if (i == index) continue;
            if (x == robot.get(i).x && y == robot.get(i).y) return 2;
        }
        return 0;
    }

    private static char direction(int idx) {
        char c = ' ';
        if (idx == 0) c = 'E';
        if (idx == 1) c = 'S';
        if (idx == 2) c = 'W';
        if (idx == 3) c = 'N';
        return c;
    }

    private static class p {
        int x, y;
        char dir;

        private p(int x, int y, char dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }
    }
}