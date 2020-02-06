import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long start = Long.parseLong(st.nextToken()), end = Long.parseLong(st.nextToken());
        if (start == end) {
            System.out.println(0);
            return;
        }
        String ans = bfs(start, end);
        System.out.println(ans.equals("NO") ? -1 : ans);
    }

    private static String bfs(long start, long end) {
        HashMap<Long, Integer> visited = new HashMap<>();
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(start, ""));
        ArrayList<String> v = new ArrayList<>();
        while (!q.isEmpty()) {
            long here = q.peek().here;
            String s = q.peek().s;
            if (here == end) {
                v.add(s);
            }
            q.poll();
            long s1 = here + here;
            long s2 = here - here;
            long s3 = here * here;
            long s4 = 0;
            if (here != 0) s4 = 1L;
            // 순서가 매우매우 중요!!
            if (visited.get(s3) == null) {
                StringBuilder sb = new StringBuilder();
                sb.append(s);
                sb.append('*');
                visited.put(s3, 1);
                q.add(new p(s3, sb.toString()));
            }
            if (visited.get(s1) == null) {
                StringBuilder sb = new StringBuilder();
                sb.append(s);
                sb.append('+');
                visited.put(s1, 1);
                q.add(new p(s1, sb.toString()));
            }
            if (visited.get(s2) == null) {
                StringBuilder sb = new StringBuilder();
                sb.append(s);
                sb.append('-');
                visited.put(s2, 1);
                q.add(new p(s2, sb.toString()));
            }
            if (visited.get(s4) == null && s4 == 1) {
                StringBuilder sb = new StringBuilder();
                sb.append(s);
                sb.append('/');
                visited.put(s4, 1);
                q.add(new p(s4, sb.toString()));
            }
        }
        if (v.size() == 0) return "NO";
        else return v.get(0);
    }

    private static class p {
        long here;
        String s;

        private p(long here, String s) {
            this.here = here;
            this.s = s;
        }
    }
}