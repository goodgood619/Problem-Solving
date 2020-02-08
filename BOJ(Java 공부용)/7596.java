import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc=1;
        while(true) {
            int n = Integer.parseInt(br.readLine());
            if(n==0) break;
            ArrayList<String> v=new ArrayList<>();
            for(int i=0;i<n;i++) {
                v.add(br.readLine());
            }
            v.sort(Comparator.naturalOrder());
            bw.write(tc+"\n");
            for(int i=0;i<v.size();i++) bw.write(v.get(i)+"\n");
            tc++;
        }
        bw.flush();
        bw.close();
    }
}