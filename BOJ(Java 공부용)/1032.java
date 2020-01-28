import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        ArrayList<String> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            v.add(br.readLine());
        }
        int length = v.get(0).length();
        for(int j=0;j<length;j++) {
            boolean check = false;
            char c = v.get(0).charAt(j);
            for(int i=1;i<v.size();i++) {
                char next = v.get(i).charAt(j);
                if(c == next) continue;
                else {
                    check = true;
                    break;
                }
            }
            if (check) {
                bw.write("?");
            } else {
                bw.write(c);
            }
        }
        bw.flush();
        bw.close();
    }
}