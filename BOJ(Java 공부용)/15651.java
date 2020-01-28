import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        ArrayList<Integer> v = new ArrayList<>();
        go(0,n,m,v);
        bw.flush();
        bw.close();
    }
    private static void go(int cnt,int n,int depth,ArrayList<Integer> v) throws IOException {
        if(cnt == depth) {
            for(int i=0;i<v.size();i++) {
                bw.write(v.get(i)+" ");
            }
            bw.write("\n");
            return;
        }
        for(int i=0;i<n;i++) {
                v.add(i+1);
                go(cnt+1,n,depth,v);
                v.remove(v.size()-1);
        }
    }
}