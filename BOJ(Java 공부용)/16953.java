import java.io.*;
import java.util.ArrayDeque;
import java.util.HashMap;;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken()), m = Long.parseLong(st.nextToken());
        HashMap<Long, Integer> map = new HashMap<>();
        bfs(n, m, map);
        System.out.println(map.get(m) == null ? -1 : map.get(m));
    }

    private static void bfs(long n, long m, HashMap<Long, Integer> map) {
        map.put(n, 1);
        ArrayDeque<Long> q = new ArrayDeque<>();
        q.add(n);
        while (!q.isEmpty()) {
            long here = q.peek();
            q.poll();
            if (here == m) break;
            for (int i = 0; i < 2; i++) {
                if (i == 0) {
                    long next = here * 2;
                    if (next > m) continue;
                    if (map.get(next) == null) {
                        map.put(next, map.get(here) + 1);
                        q.add(next);
                    }
                } else {
                    long next = here * 10 + 1;
                    if (next > m) continue;
                    if (map.get(next) == null) {
                        map.put(next, map.get(here) + 1);
                        q.add(next);
                    }
                }
            }
        }
    }
}