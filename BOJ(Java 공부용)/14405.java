import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        ArrayList<Character> v = new ArrayList<>();
        for(int i=0;i<s.length();i++) {
            v.add(s.charAt(i));
            if(go(v)) {
                v.clear();
            }
            else continue;
        }
        if(v.isEmpty()) bw.write("YES");
        else bw.write("NO");
        bw.flush();
        bw.close();
    }
    private static boolean go(ArrayList<Character> v) {
        if(v.size() == 2) {
            if(v.get(0)=='p' && v.get(1)=='i') return true;
            if(v.get(0)=='k'&& v.get(1)=='a') return true;
        }
        if(v.size() == 3) {
            if(v.get(0)=='c' && v.get(1) == 'h' && v.get(2)=='u') return true;
        }
        return false;
    }
}