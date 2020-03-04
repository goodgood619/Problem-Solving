import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        StringBuilder sb = new StringBuilder();
        long sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                sb.append(s.charAt(i));
            } else {
                if (sb.length() <= 6 && sb.length() >= 1) {
                    sum += Integer.parseInt(sb.toString());
                    sb.delete(0, sb.length());
                }
            }
        }

        if (sb.length() <= 6 && sb.length() >= 1) {
            sum += Integer.parseInt(sb.toString());
            sb.delete(0, sb.length());
        }
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }
}