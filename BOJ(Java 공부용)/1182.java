import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox  = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), s= Integer.parseInt(input[1]);
        String[] input2 = br.readLine().split(" ");
        int[] arr = new int[n];
        boolean[] visited = new boolean[n];
        for(int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(input2[i]);
        }
        for(int i=1;i<=n;i++) {
            dfs(0,0,0,i,visited,arr,s);
        }
        bw.write(ans+" ");
        bw.flush();
        bw.close();
    }
    private static void dfs(int here,int cnt,int sum,int depth,boolean[] visited,int[] arr,int s) {
        if(cnt == depth) {
            if(sum == s) ans++;
            return;
        }
        for(int i=here;i<arr.length;i++) {
            if(!visited[i]) {
                visited[i] = true;
                dfs(i+1,cnt+1,sum+arr[i],depth,visited,arr,s);
                visited[i] = false;
            }
        }
    }
}