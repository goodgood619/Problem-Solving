import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        ArrayList<String> v = new ArrayList<>();
        v.add("c=");
        v.add("c-");
        v.add("d-");
        v.add("lj");
        v.add("nj");
        v.add("s=");
        v.add("z=");
        int cnt = 0;
        for (int i = 0; i < s.length(); ) {
            if (i + 3 <= s.length()) {
                String temp = s.substring(i, i + 3);
                if (temp.equals("dz=")) {
                    i += 3;
                    cnt++;
                    continue;
                }
            }
            if (i + 2 <= s.length()) {
                String temp = s.substring(i, i + 2);
                boolean check = false;
                for (int j = 0; j < v.size(); j++) {
                    if (temp.equals(v.get(j))) {
                        check = true;
                        break;
                    }
                }
                if (check) {
                    cnt++;
                    i += 2;
                    continue;
                }
            }
            cnt++;
            i++;
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }
}