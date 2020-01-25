import java.io.*;
import java.util.ArrayDeque;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int[] arr = new int[n];
        for(int i=0;i<n;i++) {
            String[] temp = br.readLine().split(" ");
            arr[i] = Integer.parseInt(temp[0]);
        }
        System.out.println(bfs(a,b,arr));
    }
    private static int bfs(int st,int en,int[] arr) {
        ArrayDeque<p> queue = new ArrayDeque<>();
        boolean[] visited = new boolean[1000];
        visited[st] = true;
        queue.add(new p(st,0));
        while(!queue.isEmpty()) {
            int here = queue.peekFirst().here;
            int cost = queue.peekFirst().cost;
            queue.pop();
            if(here == en ) {
                return cost;
            }
            if(here>=2 && !visited[here - 1]) {
                visited[here-1] = true;
                queue.add(new p(here-1,cost+1));
            }
            if(here+1<1000 && !visited[here + 1]) {
                visited[here+1]= true;
                queue.add(new p(here+1,cost+1));
            }
            for(int i=0;i<arr.length;i++) {
                int next = arr[i];
                if(!visited[next]) {
                    visited[next] = true;
                    queue.add(new p(next,cost+1));
                }
            }
        }
        return 0;
    }
    private static class p {
        int here,cost;
        public p (int here,int cost){
            this.here = here;
            this.cost = cost;
        }
    }
}