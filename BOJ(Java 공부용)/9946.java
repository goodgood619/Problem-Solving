import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = 1;
        while (true) {
            String s1 = br.readLine();
            String s2 = br.readLine();
            if (s1.equals("END")) break;
            if (s1.length() != s2.length()) {
                bw.write("Case " + tc + ": different\n");
                tc++;
            } else {
                int[] check1 = new int[26];
                int[] check2 = new int[26];
                for (int i = 0; i < s1.length(); i++) {
                    check1[s1.charAt(i) - 'a']++;
                    check2[s2.charAt(i) - 'a']++;
                }
                boolean no = false;
                for (int i = 0; i < 26; i++) {
                    if (check1[i] != check2[i]) {
                        no = true;
                        break;
                    }
                }
                bw.write(no ? "Case " + tc + ": different\n" : "Case " + tc + ": same\n");
                tc++;
            }
        }
        bw.flush();
        bw.close();
    }
}