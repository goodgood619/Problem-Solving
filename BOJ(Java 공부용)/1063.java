import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String king = st.nextToken(), doll = st.nextToken();
        int n = Integer.parseInt(st.nextToken());
        int kx = 8 - (king.charAt(1) - '0'), ky = king.charAt(0) - 'A', dx = 8 - (doll.charAt(1) - '0'), dy = doll.charAt(0) - 'A';
        for (int i = 0; i < n; i++) {
            String move = br.readLine();
            int tkx = kx, tky = ky, tdx = dx, tdy = dy;
            if (move.equals("R")) {
                p ret = go(kx, ky, dx, dy, tkx, tky, tdx, tdy, 0);
                kx = ret.kx;
                ky = ret.ky;
                dx = ret.dx;
                dy = ret.dy;
            }
            if (move.equals("L")) {
                p ret = go(kx, ky, dx, dy, tkx, tky, tdx, tdy, 1);
                kx = ret.kx;
                ky = ret.ky;
                dx = ret.dx;
                dy = ret.dy;
            }
            if (move.equals("B")) {
                p ret = go(kx, ky, dx, dy, tkx, tky, tdx, tdy, 2);
                kx = ret.kx;
                ky = ret.ky;
                dx = ret.dx;
                dy = ret.dy;
            }
            if (move.equals("T")) {
                p ret = go(kx, ky, dx, dy, tkx, tky, tdx, tdy, 3);
                kx = ret.kx;
                ky = ret.ky;
                dx = ret.dx;
                dy = ret.dy;
            }
            if (move.equals("RT")) {
                p ret = go2(kx, ky, dx, dy, tkx, tky, tdx, tdy, 3, 0);
                kx = ret.kx;
                ky = ret.ky;
                dx = ret.dx;
                dy = ret.dy;
            }
            if (move.equals("LT")) {
                p ret = go2(kx, ky, dx, dy, tkx, tky, tdx, tdy, 3, 1);
                kx = ret.kx;
                ky = ret.ky;
                dx = ret.dx;
                dy = ret.dy;
            }
            if (move.equals("RB")) {
                p ret = go2(kx, ky, dx, dy, tkx, tky, tdx, tdy, 2, 0);
                kx = ret.kx;
                ky = ret.ky;
                dx = ret.dx;
                dy = ret.dy;
            }
            if (move.equals("LB")) {
                p ret = go2(kx, ky, dx, dy, tkx, tky, tdx, tdy, 2, 1);
                kx = ret.kx;
                ky = ret.ky;
                dx = ret.dx;
                dy = ret.dy;
            }
        }
        ky += 'A';
        kx = 8 - kx;
        dy += 'A';
        dx = 8 - dx;
        StringBuilder sb = new StringBuilder();
        sb.append((char) ky);
        sb.append(kx);
        sb.append("\n");
        sb.append((char) dy);
        sb.append(dx);
        bw.write(sb.toString() + " ");
        bw.flush();
        bw.close();
    }

    private static class p {
        int kx, ky, dx, dy;

        private p(int kx, int ky, int dx, int dy) {
            this.kx = kx;
            this.ky = ky;
            this.dx = dx;
            this.dy = dy;
        }
    }

    private static p go(int kx, int ky, int dx, int dy, int tkx, int tky, int tdx, int tdy, int dir) {
        tkx += gox[dir];
        tky += goy[dir];
        if (tkx == dx && tky == dy) {
            tdx += gox[dir];
            tdy += goy[dir];
        }
        if (!check(tkx, tky) || !check(tdx, tdy)) return new p(kx, ky, dx, dy);
        kx = tkx;
        ky = tky;
        dx = tdx;
        dy = tdy;
        return new p(kx, ky, dx, dy);
    }

    private static p go2(int kx, int ky, int dx, int dy, int tkx, int tky, int tdx, int tdy, int dir1, int dir2) {
        tkx += gox[dir1];
        tky += goy[dir2];
        if (tkx == dx && tky == dy) {
            tdx += gox[dir1];
            tdy += goy[dir2];
        }
        if (!check(tkx, tky) || !check(tdx, tdy)) return new p(kx, ky, dx, dy);
        kx = tkx;
        ky = tky;
        dx = tdx;
        dy = tdy;
        return new p(kx, ky, dx, dy);
    }

    private static boolean check(int x, int y) {
        if (x < 0 || x >= 8 || y < 0 || y >= 8) return false;
        return true;
    }

}