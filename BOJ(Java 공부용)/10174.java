import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-->0) {
            String s = br.readLine();
            boolean no = false;
            for(int i=0,j=s.length()-1;i<=j;i++,j--) {
                if(s.charAt(i)==s.charAt(j) || Math.abs(s.charAt(i)-s.charAt(j))==32) continue;
                else {
                    no=true;
                    break;
                }
            }
            if(!no) System.out.println("Yes");
            else System.out.println("No");
        }
    }
}