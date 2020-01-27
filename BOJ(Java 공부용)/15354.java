import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[]gox = {0,1,-1,0};
    static int[]goy = {1,0,0,-1};
    static double win = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        char[] v = new char[n];
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            v[i] = s.charAt(0);
        }
        int ans = 1;
        for(int i=0;i<v.length-1;i++) {
            if(v[i]==v[i+1]) continue;
            else ans++;
        }
        ans++;
        System.out.println(ans);
    }
}