import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        HashMap<String,Integer> hear = new HashMap<>();
        ArrayList<String> v= new ArrayList<>();
        for(int i=0;i<n;i++) {
            String s= br.readLine();
            if(hear.get(s) == null) {
                hear.put(s,1);
            }
        }
        for(int i=0;i<m;i++) {
            String s = br.readLine();
            if(hear.get(s) != null) {
                v.add(s);
            }
        }
        v.sort(Comparator.naturalOrder());
        bw.write(v.size()+"\n");
        for(int i=0;i<v.size();i++) bw.write(v.get(i)+"\n");
        bw.flush();
        bw.close();
    }
}