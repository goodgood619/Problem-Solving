import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String s = br.readLine();
            if (s.equals("0")) break;
            boolean check = false;
            for (int i = 0, j = s.length() - 1; i <= j; i++, j--) {
                if (s.charAt(i) == s.charAt(j)) continue;
                else {
                    check = true;
                    break;
                }
            }
            bw.write(check ? "no\n" : "yes\n");
        }
        bw.flush();
        bw.close();
    }
}