import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        ArrayList<p> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            v.add(new p(s,s.length()));
        }
        v.sort((a,b)->{
           if(a.length<b.length) return -1;
           else if(a.length>b.length) return 1;
           else {
               return a.s.compareTo(b.s);
           }
        });
        String temp = v.get(0).s;
        bw.write(temp+"\n");
        for(int i=1;i<v.size();i++) {
            if(temp .equals(v.get(i).s)) continue;
            bw.write(v.get(i).s+"\n");
            temp = v.get(i).s;
        }
        bw.flush();
        bw.close();
    }
    private static class p{
        String s;
        int length;
        private p(String s,int length) {
            this.s = s;
            this.length = length;
        }
    }
}