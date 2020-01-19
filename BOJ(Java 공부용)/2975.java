import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]), b = Integer.parseInt(input[2]);
            String c = input[1];
            if(a ==0 && b==0 && c.equals("W")) break;
            if(c.equals("W")) {
                a-=b;
                if(a <-200) {
                    System.out.println("Not allowed");
                } else {
                    System.out.println(a);
                }
            } else {
                a+=b;
                if(a <-200) {
                    System.out.println("Not allowed");
                } else {
                    System.out.println(a);
                }
            }
        }
    }
}