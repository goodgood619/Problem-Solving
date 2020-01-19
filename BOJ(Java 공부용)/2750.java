import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
public class Main {
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            v.add(Integer.parseInt(br.readLine()));
        }
        Collections.sort(v);
        for(int i=0;i<v.size();i++) {
            bw.write(v.get(i)+"\n");
            bw.flush();
        }
    }

}
