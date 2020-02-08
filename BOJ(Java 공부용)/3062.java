import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s = br.readLine();
            StringBuilder sb = new StringBuilder();
            sb.append(s);
            int a = Integer.parseInt(s);
            sb.reverse();
            a += Integer.parseInt(sb.toString());
            s = String.valueOf(a);
            boolean no = false;
            for (int i = 0, j = s.length() - 1; i <= j; i++, j--) {
                if (s.charAt(i) == s.charAt(j)) {
                    continue;
                } else {
                    no = true;
                    break;
                }
            }
            bw.write(no ? "NO\n" : "YES\n");
        }
        bw.flush();
        bw.close();
    }
}