import java.io.*;
import java.util.Arrays;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        char[] c = new char[s.length()];
        for(int i=0;i<s.length();i++) {
            c[i] = s.charAt(i);
        }
        Arrays.sort(c);
        for(int i=c.length-1;i>=0;i--) {
            bw.write(c[i]);
        }
        bw.flush();
        bw.close();
    }
}