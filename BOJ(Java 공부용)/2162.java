import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.Long.max;
import static java.lang.Long.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<PP> v = new ArrayList<>();
        int[] parent = new int[n];
        int[] size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long x1 = Long.parseLong(st.nextToken()), y1 = Long.parseLong(st.nextToken()), x2 = Long.parseLong(st.nextToken()), y2 = Long.parseLong(st.nextToken());
            v.add(new PP(x1, y1, x2, y2));
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                PP here = v.get(i);
                PP next = v.get(j);
                long ccw1 = ccw(here.x1, here.y1, here.x2, here.y2, next.x1, next.y1);
                long ccw2 = ccw(here.x1, here.y1, here.x2, here.y2, next.x2, next.y2);
                long ccw3 = ccw(next.x1, next.y1, next.x2, next.y2, here.x1, here.y1);
                long ccw4 = ccw(next.x1, next.y1, next.x2, next.y2, here.x2, here.y2);
                if (ccw1 * ccw2 > 0 || ccw3 * ccw4 > 0) continue;
                else {
                    if (ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0 && !cross(here.x1, here.y1, here.x2, here.y2, next.x1, next.y1, next.x2, next.y2))
                        continue;
                    if (find(i, parent) != find(j, parent)) union(i, j, parent, size);
                }
            }
        }
        int cnt = 0, max = 0;
        for (int i = 0; i < n; i++) {
            if (size[i] != 0) {
                cnt++;
                if (max < size[i]) max = size[i];
            }
        }
        bw.write(cnt + "\n" + max + "\n");
        bw.flush();
        bw.close();
    }

    private static void union(int u, int v, int[] parent, int[] Size) {
        u = find(u, parent);
        v = find(v, parent);
        if (u == v) return;
        if (Size[u] < Size[v]) {
            Size[v] += Size[u];
            Size[u] = 0;
            parent[u] = v;
        } else {
            Size[u] += Size[v];
            Size[v] = 0;
            parent[v] = u;
        }
    }

    private static int find(int u, int[] parent) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u], parent);
    }

    private static boolean cross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4) {
        if (x1 == x2 && x2 == x3 && x3 == x4) {
            return !check(y1, y2, y3, y4);
        } else {
            return !check(x1, x2, x3, x4);
        }
    }

    private static boolean check(long x1, long x2, long x3, long x4) {
        long maxx = max(x1, x2);
        long minx = min(x3, x4);
        if (maxx < minx) return true;
        maxx = max(x3, x4);
        minx = min(x1, x2);
        return maxx < minx;
    }

    private static long ccw(long x1, long y1, long x2, long y2, long x3, long y3) {
        return (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    }
}

class PP {
    long x1, y1, x2, y2;

    PP(long x1, long y1, long x2, long y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }
}

class P {
    long x;
    long y;

    P(long x, long y) {
        this.x = x;
        this.y = y;
    }
}