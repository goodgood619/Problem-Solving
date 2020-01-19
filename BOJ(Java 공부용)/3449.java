import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s= br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        for(int i=0;i<n;i++) {
            String s1 = br.readLine();
            String s2 = br.readLine();
            int cnt=0;
            for(int j=0;j<s1.length();j++) {
                if(s1.charAt(j) != s2.charAt(j)) cnt++;
            }
            bw.write("Hamming distance is "+String.valueOf(cnt)+".\n");
            bw.flush();
        }
    }
}