import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            bfs(n);
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    private static void bfs(int n) throws IOException {
        Deque<Integer> q = new ArrayDeque<>();
        int[] path = new int[n + 1];
        int[] path2 = new int[n + 1];
        q.add(1);
        path[1] = -1;
        path2[1] = 1;
        boolean[] visited = new boolean[n + 1];
        visited[1] = true;
        boolean ok = false;
        int end = 0;
        while (!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            if (here % n == 0) {
                ok = true;
                end = here;
                break;
            }
            int next = (here * 10) % n;
            int next2 = (here * 10 + 1) % n;
            if (!visited[next]) {
                visited[next] = true;
                q.add(next);
                path[next] = here;
                path2[next] = 0;
            }
            if (!visited[next2]) {
                visited[next2] = true;
                q.add(next2);
                path[next2] = here;
                path2[next2] = 1;
            }
        }
        if (!ok) {
            bw.write("BRAK");
        } else {
            print(path, path2, end);
        }
    }

    private static void print(int[] path, int[] path2, int end) throws IOException {
        if (path[end] == -1) {
            bw.write("1");
            return;
        }
        print(path, path2, path[end]);
        bw.write(path2[end] + "");
    }
}