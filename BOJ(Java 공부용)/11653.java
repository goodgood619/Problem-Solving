import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int p = 2;
        ArrayList<Integer> v = new ArrayList<>();
        while(n > 1) {
            if(n%p ==0 ){
                v.add(p);
                n /= p;
                p = 2;
            }
            else p++;
        }
        for(int i=0;i<v.size();i++) {
            bw.write(v.get(i)+"\n");
        }
        bw.flush();
        bw.close();
    }
}