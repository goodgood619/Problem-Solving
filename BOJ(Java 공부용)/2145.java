import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String s = br.readLine();
            if (s.equals("0")) break;

            while (s.length() != 1) {
                int sum = 0;
                for (int i = 0; i < s.length(); i++) {
                    sum += (s.charAt(i) - '0');
                }
                s = String.valueOf(sum);
            }
            bw.write(s + "\n");
        }
        bw.flush();
        bw.close();
    }
}