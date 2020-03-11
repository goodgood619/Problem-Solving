import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()), i = 0;
        while (n > 0) {
            i++;
            String s = String.valueOf(i);
            n -= s.length();
            if (n <= 0) {
                bw.write(s.charAt(s.length() - 1 + n));
                break;
            }
        }
        bw.flush();
        bw.close();
    }
}