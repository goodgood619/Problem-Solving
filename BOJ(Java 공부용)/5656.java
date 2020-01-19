import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int Case = 1;
        while(true) {
            String[] input = br.readLine().split(" ");
            if(input[1].equals("E")) break;
            int a = Integer.parseInt(input[0]), b = Integer.parseInt(input[2]);
            String s = input[1];
            boolean check = false;
            if(s.equals(">")) {
                if(a>b) check = true;
            }
            if(s.equals(">=")) {
                if(a>=b) check = true;
            }
            if(s.equals("<")) {
                if(a<b) check = true;
            }
            if(s.equals("<=")) {
                if(a<=b) check = true;
            }
            if(s.equals("==")) {
                if(a==b) check = true;
            }
            if(s.equals("!=")) {
                if(a!=b) check = true;
            }
            System.out.println("Case "+Case + ": "+check);
            Case++;
        }
    }
}