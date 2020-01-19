import java.io.*;
import java.util.*;

import static java.lang.Math.pow;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s= br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        for(int i=0;i<n;i++) {
            String temp = br.readLine();
            int cnt=0,sum=0;
            for(int j=temp.length()-1;j>=0;j--) {
                sum += pow(2,cnt++)*(temp.charAt(j)-'0');
            }
            System.out.println(sum);
        }
    }
}