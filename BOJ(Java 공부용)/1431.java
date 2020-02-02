import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        ArrayList<p> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            int sum = 0;
            for(int j=0;j<s.length();j++) {
                char c = s.charAt(j);
                if(c>='0' && c<='9') sum += (c-'0');
            }
            v.add(new p(s.length(),sum,s));
        }
        v.sort((a,b)->{
           if(a.size <b.size) return -1;
           else if(a.size>b.size) return 1;
           else {
               if(a.sum<b.sum) return -1;
               else if(a.sum> b.sum) return 1;
               else {
                   return a.s.compareTo(b.s);
               }
           }
        });

        for(int i=0;i<v.size();i++) {
            bw.write(v.get(i).s+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static class p {
        int size,sum;
        String s;
        private p(int size,int sum,String s) {
            this.s = s;
            this.size = size;
            this.sum = sum;
        }
    }
}