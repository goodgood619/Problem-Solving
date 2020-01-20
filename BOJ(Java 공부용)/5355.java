import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String ss[]= br.readLine().split(" ");
        int n = Integer.parseInt(ss[0]);
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            double a = Double.parseDouble(input[0]);
            for(int j=1;j<input.length;j++) {
                String s = input[j];
                if(s.equals("@")) {
                    a *=3;
                }
                if(s.equals("%")) {
                    a+=5;
                }
                if(s.equals("#")) {
                    a-=7;
                }
            }
            System.out.println(String.format("%.2f",a));
        }
    }
}