import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine();
        ArrayList<String> v = new ArrayList<>();
        for(int i=0;i<2;i++) {
            String s = br.readLine();
            v.add(s);
        }
        long[][][] dp = new long[101][2][21];
        for(int i=0;i<=100;i++) {
            for(int j=0;j<2;j++) {
                for(int k=0;k<=20;k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        bw.write(go(0,0,0,dp,word,v)+go(0,1,0,dp,word,v)+"\n");
        bw.flush();
        bw.close();
    }
    private static long go(int index,int c,int w,long[][][] dp,String word,ArrayList<String> v) {
        if(w>=word.length()) return 1;
        if(dp[index][c][w]!= -1) return dp[index][c][w];
        dp[index][c][w] = 0;
        for(int i=index;i<v.get(c).length();i++) {
            if(v.get(c).charAt(i) == word.charAt(w)) {
                dp[index][c][w] += go(i+1,(c+1)%2,w+1,dp,word,v);
            }
        }
        return dp[index][c][w];
    }
}