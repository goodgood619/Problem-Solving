import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int cnt = 10;
    static boolean ans = false;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        if(n<=10) System.out.println(n-1);
        else if(n>1023) System.out.println(-1);
        else {
            int k = 2;
            ArrayList<Character> temp = new ArrayList<>();
            boolean[] visited = new boolean[10];
            for(int i=2;i<=10;i++) {
                go(n,0,k,visited,temp);
                k++;
            }
        }
    }
    private static void go(int n,int depth,int Depth, boolean[] visited, ArrayList<Character> temp) throws IOException {
        if(ans) return;
        if(depth == Depth) {
            boolean check = false;
            for(int i=0;i<depth-1;i++) {
                if(temp.get(i) < temp.get(i+1)) {
                    check = true;
                    break;
                }
            }
            if(check) return;
            cnt++;
            if(cnt == n) {
                for(int i=0;i<temp.size();i++) {
                    bw.write(temp.get(i));
                }
                bw.flush();
                bw.close();
                ans = true;
            }
        }
        for(int i=0;i<10;i++) {
            if(!visited[i]) {
                visited[i] = true;
                temp.add((char) (i+'0'));
                go(n,depth+1,Depth,visited,temp);
                temp.remove(temp.size()-1);
                visited[i] = false;

            }
        }
    }
}