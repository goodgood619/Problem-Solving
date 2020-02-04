import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[9];
        boolean[] visited = new boolean[9];
        for(int i=0;i<9;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        go(0,0,0,arr,visited);

    }
    private static void go(int here,int cnt,int sum,int[] arr,boolean[] visited) throws IOException {
        if(here>=10) return;
        if(cnt == 7) {
            if(sum == 100) {
                for(int i=0;i<9;i++) {
                    if(visited[i]) bw.write(arr[i]+"\n");
                }
                bw.flush();
                bw.close();
                System.exit(0);
            }
            return;
        }
        for(int i=here;i<9;i++) {
            if(!visited[i]) {
                visited[i] = true;
                go(i+1,cnt+1,sum+arr[i],arr,visited);
                visited[i] = false;
            }
        }
    }
}