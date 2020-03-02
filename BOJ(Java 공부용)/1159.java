import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] cnt = new int[26];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            cnt[s.charAt(0) - 'a']++;
        }
        boolean check = false;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] >= 5) {
                bw.write((char) (i + 'a'));
                check = true;
            }
        }
        if (check) bw.flush();
        else {
            bw.write("PREDAJA");
            bw.flush();
        }
        bw.close();
    }
}