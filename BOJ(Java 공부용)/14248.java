import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;

class Main {
    static int[] gox = {1,0,-1,0};
    static int[] goy = {0,1,0,-1};
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] arr = new int[input.length];
        for (int i=0;i<input.length;i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        int start = Integer.parseInt(br.readLine());
        start--;
        bfs(start,arr,n);
    }
    private static void bfs(int start, int[] arr,int n) throws IOException {
        boolean[] visited = new boolean[n];
        visited[start] = true;
        Deque<Integer> q = new ArrayDeque<>();
        q.add(start);
        while (!q.isEmpty()) {
            int here = q.peekFirst();
            q.pollFirst();
            int rightJump = here + arr[here];
            int leftJump = here - arr[here];
            if (rightJump < n && !visited[rightJump]) {
                visited[rightJump] = true;
                q.push(rightJump);
            }
            if (leftJump >= 0 && !visited[leftJump]) {
                visited[leftJump] = true;
                q.push(leftJump);
            }
        }

        int ans = 0;
        for (int i = 0; i < visited.length; i++) {
            if (visited[i]) {
                ans++;
            }
        }

        bw.write(ans+"");
        bw.flush();
    }
}