import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            boolean[] visited = new boolean[10001];
            bfs(a, b, visited);
        }
        bw.flush();
        bw.close();
    }

    private static void bfs(int a, int b, boolean[] visited) throws IOException {
        visited[a] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        StringBuilder sb2 = new StringBuilder();
        q.add(new p(a, sb2));
        while (!q.isEmpty()) {
            int num = q.peek().num;
            StringBuilder sb = q.peek().sb;
            if (num == b) {
                bw.write(sb.toString() + "\n");
                break;
            }
            q.poll();
            int d = (num * 2) % 10000;
            if (!visited[d]) {
                visited[d] = true;
                StringBuilder temp = new StringBuilder(sb);
                temp.append('D');
                q.add(new p(d, temp));
            }
            int s = num - 1;
            if (s < 0) s = 9999;
            if (!visited[s]) {
                visited[s] = true;
                StringBuilder temp = new StringBuilder(sb);
                temp.append('S');
                q.add(new p(s, temp));
            }
            int l = (num % 1000) * 10 + (num / 1000);
            if (!visited[l]) {
                visited[l] = true;
                StringBuilder temp = new StringBuilder(sb);
                temp.append('L');
                q.add(new p(l, temp));
            }
            int r = (num % 10) * 1000 + (num / 10);
            if (!visited[r]) {
                visited[r] = true;
                StringBuilder temp = new StringBuilder(sb);
                temp.append('R');
                q.add(new p(r, temp));
            }
        }
    }

    private static class p {
        int num;
        StringBuilder sb;

        private p(int num, StringBuilder sb) {
            this.num = num;
            this.sb = sb;
        }
    }
}