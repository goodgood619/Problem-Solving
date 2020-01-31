import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            if (n == 0) break;
            int[] arr = new int[n];
            boolean[] visited = new boolean[n];
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=1;i<input.length;i++) {
                arr[i-1] = Integer.parseInt(input[i]);
            }
            go(0,0,6,arr,visited,temp);
            bw.write("\n");
            bw.flush();
        }
        bw.close();
    }
    private static void go(int here,int cnt,int depth,int[] arr,boolean[] visited,ArrayList<Integer> temp) throws IOException {
        if(cnt == depth) {
            for(int i=0;i<temp.size();i++) {
                bw.write(temp.get(i)+" ");
            }
            bw.write("\n");
            return;
        }
        for(int i=here;i<arr.length;i++) {
            if(!visited[i]) {
                visited[i] = true;
                temp.add(arr[i]);
                go(i+1,cnt+1,depth,arr,visited,temp);
                temp.remove(temp.size()-1);
                visited[i] = false;
            }
        }
    }
}