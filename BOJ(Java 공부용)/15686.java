import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.min;
import static java.lang.Math.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = (int) 1e9;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][n];
        ArrayList<p> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if(board[i][j] == 2) v.add(new p(i,j));
            }
        }

        boolean[] visited = new boolean[v.size()];
        go(0,0,m,v,visited,board,n);
        bw.write(ans+"\n");
        bw.flush();
        bw.close();
    }
    private static void go(int here,int cnt,int depth,ArrayList<p> v, boolean[] visited,int[][] board, int n) {
        if(cnt == depth) {
            bfs(v,visited,board,n);
            return;
        }
        for(int i=here;i<v.size();i++) {
            if(!visited[i]) {
                visited[i] = true;
                go(i+1,cnt+1,depth,v,visited,board,n);
                visited[i] = false;
            }
        }
    }
    private static void bfs(ArrayList<p> v,boolean[] visited,int[][] board, int n) {
        ArrayList<p> temp = new ArrayList<>();
        for(int i=0;i<v.size();i++) {
            if(visited[i]) temp.add(new p(v.get(i).x,v.get(i).y));
        }
        ArrayList<p> home = new ArrayList<>();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == 1) {
                    home.add(new p(i,j));
                }
            }
        }
        int tempans = 0;
        for(int i=0;i<home.size();i++) {
            int tempdist = (int) 1e9;
            for(int j=0;j<temp.size();j++) {
                tempdist = min(tempdist,abs(home.get(i).x-temp.get(j).x)+abs(home.get(i).y-temp.get(j).y));
            }
            tempans += tempdist;
        }
        ans = min(ans,tempans);
    }
    private static class p {
        int x,y;
        private p(int x,int y) {
            this.x = x;
            this.y = y;
        }
    }
}