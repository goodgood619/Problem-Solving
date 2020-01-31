import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] board = new int[5][5];
        for(int i=0;i<5;i++) {
            String[] input = br.readLine().split(" ");
            for(int j=0;j<input.length;j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }
        HashSet<ArrayList<Character>> set = new HashSet<>();
        ArrayList<Character> temp = new ArrayList<>();
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                temp.add((char) (board[i][j]+'0'));
                dfs(i,j,1,6,temp,set,board);
                temp.remove(temp.size()-1);
            }
        }
        bw.write(set.size()+"\n");
        bw.flush();
        bw.close();
    }
    private static void dfs(int x,int y,int cnt,int depth,ArrayList<Character> temp,HashSet<ArrayList<Character>> set,int[][] board) {
        if(cnt == depth) {
            if(!set.contains(temp)) {
                set.add(temp);
            }
            return;
        }
        for(int i=0;i<4;i++) {
            int nx = x+gox[i],ny = y+goy[i];
            if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            temp.add((char)(board[nx][ny]+'0'));
            dfs(nx,ny,cnt+1,depth,temp,set,board);
            temp.remove(temp.size()-1);
        }
    }
}