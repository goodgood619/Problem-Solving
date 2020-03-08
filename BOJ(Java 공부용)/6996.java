import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String first = st.nextToken(), second = st.nextToken();
            int[] check1 = new int[26], check2 = new int[26];
            for (int i = 0; i < first.length(); i++) {
                check1[first.charAt(i) - 'a']++;
            }
            for (int i = 0; i < second.length(); i++) {
                check2[second.charAt(i) - 'a']++;
            }
            boolean no = false;
            for (int i = 0; i < 26; i++) {
                if (check1[i] != check2[i]) {
                    no = true;
                    break;
                }
            }
            if (no) bw.write(first + " & " + second + " are NOT anagrams.\n");
            else bw.write(first + " & " + second + " are anagrams.\n");
        }
        bw.flush();
        bw.close();
    }
}