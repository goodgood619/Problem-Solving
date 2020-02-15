import java.io.*;
import static java.lang.StrictMath.abs;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();
        int[] check1 = new int[26];
        int[] check2 = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            check1[s1.charAt(i) - 'a']++;
            ;
        }
        for (int i = 0; i < s2.length(); i++) {
            check2[s2.charAt(i) - 'a']++;
        }
        int sum = 0;
        for (int i = 0; i < 26; i++) sum += abs(check1[i] - check2[i]);
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }
}