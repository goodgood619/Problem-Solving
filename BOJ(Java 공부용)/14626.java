import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static double win = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int sum = 0, temp = 1;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '*') {
                if (i % 2 == 0) temp = 1;
                else temp = 3;
            } else {
                if (i % 2 == 0) sum += (c - '0');
                else sum = sum + 3 * (c - '0');
            }
        }
        if (sum % 10 == 0) bw.write("0");
        else {
            for (int i = 1; ; i++) {
                if ((sum + temp * i) % 10 == 0) {
                    temp = i;
                    break;
                }
            }
            bw.write(temp + "");
        }
        bw.flush();
        bw.close();
    }
}