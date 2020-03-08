import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int radix = 10;
        if (s.substring(0, 2).equals("0x")) {
            radix = 16;
            s = s.substring(2);
        } else if (s.charAt(0) == '0') radix = 8;
        bw.write(Integer.parseInt(s, radix) + " ");
        bw.flush();
        bw.close();
    }
}