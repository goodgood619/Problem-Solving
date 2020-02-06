import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<p> v = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken()), y = Long.parseLong(st.nextToken());
            v.add(new p(x, y));
        }
        v.sort((a, b) -> {
            if (a.x < b.x) return -1;
            else if (a.x > b.x) return 1;
            else {
                if (a.y < b.y) return -1;
                else if (a.y > b.y) return 1;
                else return 0;
            }
        });
        ArrayDeque<Integer> up = new ArrayDeque<>();
        ArrayDeque<Integer> down = new ArrayDeque<>();
        up.add(0);
        up.add(1);
        int ptr = 2;
        while (ptr < v.size()) {
            int second = up.peekLast();
            up.pollLast();
            int first = up.peekLast();
            up.pollLast();
            long ccw1 = ccw(v.get(first), v.get(second), v.get(ptr));
            if (ccw1 > 0) {
                up.add(first);
                up.add(second);
                up.add(ptr);
                ptr++;
            } else {
                up.add(first);
                if (up.size() == 1) {
                    up.add(ptr);
                    ptr++;
                }
            }
        }
        down.add(v.size() - 1);
        down.add(v.size() - 2);
        ptr = v.size() - 3;
        while (ptr >= 0) {
            int second = down.peekLast();
            down.pollLast();
            int first = down.peekLast();
            down.pollLast();
            long ccw1 = ccw(v.get(first), v.get(second), v.get(ptr));
            if (ccw1 > 0) {
                down.add(first);
                down.add(second);
                down.add(ptr);
                ptr--;
            } else {
                down.add(first);
                if (down.size() == 1) {
                    down.add(ptr);
                    ptr--;
                }
            }
        }
        HashMap<Integer, Integer> m = new HashMap<>();
        int cnt = 0;
        while (!up.isEmpty()) {
            int here = up.peekLast();
            up.pollLast();
            if (m.get(here) == null) {
                m.put(here, 1);
                cnt++;
            }
        }
        while (!down.isEmpty()) {
            int here = down.peekLast();
            down.pollLast();
            if (m.get(here) == null) {
                m.put(here, 1);
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    private static long ccw(p a, p b, p c) {
        return (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    }

    private static class p {
        long x, y;

        private p(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }
}