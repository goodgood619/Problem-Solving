import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sh = Integer.parseInt(st.nextToken()), sm = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int eh = Integer.parseInt(st.nextToken()), em = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(br.readLine()), cnt = 0;
        int start = 60 * sh + sm, end = 60 * eh + em;
        for (int i = start; i <= end; i++) {
            int ch = i / 60, cm = i % 60;
            StringBuilder sb = new StringBuilder();
            if (ch < 10) sb.append('0');
            sb.append(ch);
            if (cm < 10) sb.append('0');
            sb.append(cm);
            for (int j = 0; j < sb.length(); j++) {
                if ((sb.charAt(j) - '0') == n) {
                    cnt++;
                    break;
                }
            }
        }
        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}