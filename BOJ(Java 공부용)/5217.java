import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        for(int i=0;i<n;i++){
            String[] s = br.readLine().split(" ");
            int num = Integer.parseInt(s[0]);
            ArrayList<p> v = new ArrayList<>();
            for(int j=1;;j++) {
                if(j<num-j) {
                    p temp = new p(j,num-j);
                    v.add(temp);
                } else break;
            }
            System.out.print("Pairs for "+num+":");
            if(v.size()==1) {
                System.out.print(" "+v.get(0).a + " "+v.get(0).b);
            } else {
                for(int j=0;j<v.size();j++) {
                    if(j==v.size()-1) {
                        System.out.print(" "+v.get(j).a + " "+v.get(j).b+" ");
                    } else {
                        System.out.print(" "+v.get(j).a + " "+v.get(j).b+",");
                    }
                }
            }
            System.out.println();
        }
    }
    static final class p {
        Integer a,b;
        public p(Integer a,Integer b) {
            this.a = a;
            this.b = b;
        }
    }
}