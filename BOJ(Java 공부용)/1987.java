import java.io.*;
import java.util.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        boolean[][] visited = new boolean[n][m];
        boolean[] check = new boolean[26];
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            for(int j=0;j<s.length();j++) {
                board[i][j] = s.charAt(j);
            }
        }

        System.out.println(dfs(0,0,1,visited,check,board,n,m));
    }
    private static int dfs(int x,int y,int cnt,boolean[][] visited,boolean[] check,char[][] board,int n,int m) {
        visited[x][y] = true;
        check[board[x][y]-'A'] = true;
        int ret = cnt;
        for(int i=0;i<4;i++) {
            int nx = x+gox[i], ny = y+goy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || check[board[nx][ny]-'A'] ) continue;
            ret =  max(ret,dfs(nx,ny,cnt+1,visited,check,board,n,m));
        }
        visited[x][y] =false;
        check[board[x][y]-'A'] = false;
        return ret;
    }
}