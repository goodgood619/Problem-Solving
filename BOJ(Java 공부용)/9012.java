import java.io.*;
import java.util.ArrayDeque;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        for(int i=0;i<n;i++) {
            ArrayDeque<Character> st = new ArrayDeque<>();
            boolean check = false;
            String[] s = br.readLine().split(" ");
            for(int j=0;j<s[0].length();j++) {
                if(s[0].charAt(j) == '(') {
                    st.push(s[0].charAt(j));
                }else{
                    if(st.isEmpty()) {
                        check = true;
                        break;
                    }
                    st.pop();
                }
            }
            if(check || !st.isEmpty()) bw.write("NO\n");
            else bw.write("YES\n");
        }
        bw.flush();
    }
}
