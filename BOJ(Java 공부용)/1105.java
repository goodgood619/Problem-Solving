import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1, 1, 1, -1, -1};
    static int[] goy = {1, -1, 0, 0, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String a = st.nextToken(), b = st.nextToken();
        if (a.length() != b.length()) bw.write("0");
        else {
            int cnt = 0;
            for (int i = 0; i < a.length(); i++) {
                boolean b1 = a.charAt(i) == b.charAt(i);
                if (a.charAt(i) == '8' && b1) cnt++;
                else if (b1) continue;
                else break;
            }
            bw.write(cnt + " ");
        }
        bw.flush();
        bw.close();

    }
}