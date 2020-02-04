import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] board =new int[3][3];
        StringBuilder sb = new StringBuilder();
        HashMap<Integer,Integer> cnt = new HashMap<>();
        for(int i=0;i<3;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0;j<3;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if(board[i][j] == 0) board[i][j] = 9;
                sb.append(board[i][j]);
            }
        }
        bfs(sb,cnt);
        Object value = cnt.get(123456789);
        System.out.println(value==null?-1:value);
    }
    private static void bfs(StringBuilder sb, HashMap<Integer,Integer> cnt) {
        int start = Integer.parseInt(sb.toString());
        cnt.put(start,0);
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(start);
        while(!q.isEmpty()) {
            int num = q.peek();
            q.poll();
            StringBuilder snum = new StringBuilder();
            snum.append(num);
            int z = 0;
            for(int i=0;i<snum.length();i++) {
                if(snum.charAt(i)== '9') {
                    z = i;
                    break;
                }
            }
            int x = z / 3 , y = z % 3;
            for(int i=0;i<4;i++) {
                int nx = x+gox[i], ny = y + goy[i];
                if(nx<0 || nx>=3 || ny<0 || ny>=3) continue;
                StringBuilder next = new StringBuilder();
                next.append(snum);
                char l = next.charAt(x*3+y), r = next.charAt(nx*3+ny);
                next.setCharAt(nx*3+ny,l);
                next.setCharAt(x*3+y,r);
                int nextnum = Integer.parseInt(next.toString());
                if(cnt.get(nextnum) == null) {
                    cnt.put(nextnum,cnt.get(num)+1);
                    q.add(nextnum);
                }
            }
        }
    }
}