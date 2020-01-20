import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String ss[]= br.readLine().split(" ");
        int n = Integer.parseInt(ss[0]),q1=0,q2=0,q3=0,q4=0,axis=0;
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]), b = Integer.parseInt(input[1]);
            if(a == 0 || b==0) axis++;
            else if(a>0 && b>0) q1++;
            else if(a<0 && b>0) q2++;
            else if(a<0 && b<0) q3++;
            else q4++;
        }
        bw.write("Q1: "+String.valueOf(q1)+"\n");
        bw.write("Q2: "+String.valueOf(q2)+"\n");
        bw.write("Q3: "+String.valueOf(q3)+"\n");
        bw.write("Q4: "+String.valueOf(q4)+"\n");
        bw.write("AXIS: "+String.valueOf(axis));
        bw.flush();
        bw.close();
    }
}