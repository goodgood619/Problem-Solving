import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String s = br.readLine();
            if (s.equals("*")) break;
            boolean[] check = new boolean[26];
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == ' ') continue;
                check[s.charAt(i) - 'a'] = true;
            }
            boolean no = false;
            for (int i = 0; i < 26; i++) {
                if (!check[i]) {
                    no = true;
                    break;
                }
            }
            bw.write(no ? "N\n" : "Y\n");
        }
        bw.flush();
        bw.close();
    }
}