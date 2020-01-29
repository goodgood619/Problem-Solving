import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        String grocery = br.readLine();
        ArrayList<String> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            v.add(br.readLine().split(" ")[0]);
        }
        int cnt = 0;
        for(int i=0;i<v.size();i++) {
            boolean ok = false;
            ArrayList<Integer> st = new ArrayList<>();
            for(int j=0;j<v.get(i).length();j++) {
                if(v.get(i).charAt(j) == grocery.charAt(0)) {
                    st.add(j);
                }
            }
            if(st.isEmpty()) continue;

            // 시작
            for(int j=0;j<st.size();j++) {
                    for(int p =1 ;p+st.get(j)<v.get(i).length();p++) {
                        int idx = 0;
                        for (int k = st.get(j); k < v.get(i).length(); k += p) {
                            if(idx == grocery.length()) break;
                            if (v.get(i).charAt(k) == grocery.charAt(idx)) {
                                idx++;
                            }
                            else break;
                        }
                        if (idx == grocery.length()) {
                            ok = true;
                            break;
                        }
                    }
                    if(ok) break;
            }
            if(ok) cnt++;
        }
        bw.write(cnt+"\n");
        bw.flush();
        bw.close();
    }
}