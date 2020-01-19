import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s= br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        for(int i=0;i<n;i++) {
            int vowel =0,con =0;
            String temp = br.readLine();
            for(int j=0;j<temp.length();j++) {
                char c = temp.charAt(j);
                if(c== ' ') continue;
                if(c == 'A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u') vowel++;
                else con++;
            }
            bw.write(String.valueOf(con)+" "+String.valueOf(vowel)+"\n");
            bw.flush();
        }
    }
}