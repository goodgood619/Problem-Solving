import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static int min = (int) 1e9;
    static int max = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            String s = br.readLine();
            int[] check = new int[26];
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == ' ') continue;
                check[s.charAt(i) - 'a']++;
            }
            int max = 0;
            char c = ' ';
            for (int i = 0; i < 26; i++) {
                if (max < check[i]) {
                    max = check[i];
                    c = (char) (i + 'a');
                }
            }
            int same = 0;
            for (int i = 0; i < 26; i++) {
                if (max == check[i]) {
                    same++;
                }
            }
            if (same >= 2) bw.write("?\n");
            else bw.write(c + "\n");
        }
        bw.flush();
        bw.close();
    }

}