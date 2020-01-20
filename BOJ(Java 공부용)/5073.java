import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String ss[] = br.readLine().split(" ");
            int a = Integer.parseInt(ss[0]),b = Integer.parseInt(ss[1]),c = Integer.parseInt(ss[2]);
            if(a==0 && b==0 && c==0) break;
            ArrayList<Integer> v = new ArrayList<>();
            v.add(a);
            v.add(b);
            v.add(c);
            Collections.sort(v);
            a = v.get(0);
            b= v.get(1);
            c= v.get(2);
            if(a+b<=c) System.out.println("Invalid");
            else if(a==b && b==c && c==a) System.out.println("Equilateral");
            else if(a!=b && b!=c && c!=a) System.out.println("Scalene");
            else System.out.println("Isosceles");
        }
    }
}