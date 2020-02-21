import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        for (int i = 1; i < s.length(); i++) {
            String first = s.substring(0, i);
            String second = s.substring(i, s.length());
            int one = 1, two = 1;
            for (int j = 0; j < first.length(); j++) {
                one *= (first.charAt(j) - '0');
            }
            for (int j = 0; j < second.length(); j++) {
                two *= (second.charAt(j) - '0');
            }
            if (one == two) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}