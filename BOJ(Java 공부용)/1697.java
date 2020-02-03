import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {-1,1,2};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        bfs(n,k);
    }
    private static void bfs(int here,int end) {
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(here,0));
        boolean[] visited = new boolean[200001];
        visited[here] = true;
        while(!q.isEmpty()) {
            int here1 = q.peek().here;
            int cnt = q.peek().cnt;
            q.poll();
            if(here1 == end) {
                System.out.println(cnt);
                return;
            }
            for(int i=0;i<3;i++) {
                if(i == 2) {
                    int nx = here1 * gox[i];
                    if (nx>=0 && nx <= 100000 && !visited[nx]) {
                        visited[nx] = true;
                        q.add(new p(nx,cnt+1));
                    }
                }
                else {
                    int nx = here1 + gox[i];
                    if (nx>=0 && nx <= 100000 && !visited[nx]) {
                        visited[nx] = true;
                        q.add(new p(nx,cnt+1));
                    }
                }
            }
        }
    }
    private static class p {
        int here,cnt;
        private p(int here,int cnt) {
            this.here = here;
            this.cnt = cnt;
        }
    }
}