import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();
        int[] fail = new int[1000001];
        int j =0 ;
        for(int i=1;i<s2.length();i++) {
            while(j>0 && s2.charAt(i)!= s2.charAt(j)) j = fail[j-1];
            if(s2.charAt(i)== s2.charAt(j)) {
                fail[i] = j+1;
                j++;
            }
        }
        j = 0;
        int idx =0 , ans = 0;
        ArrayList<Integer> v= new ArrayList<>();
        for(int i=0;i<s1.length();i++) {
            while(j>0 && s1.charAt(i) != s2.charAt(j)) j = fail[j-1];
            if(s1.charAt(i) == s2.charAt(j)) {
                if(j == s2.length()-1) {
                    ans++;
                    v.add(i-j+1);
                    j = fail[j];
                    continue;
                }
                j++;
            }
        }

        bw.write(v.size()+"\n");
        for(int i=0;i<v.size();i++) bw.write(v.get(i)+" ");
        bw.flush();
        bw.close();
    }
}