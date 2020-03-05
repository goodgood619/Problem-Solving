import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1, 1, 1, -1, -1};
    static int[] goy = {1, -1, 0, 0, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            cnt[s.charAt(i) - 'A']++;
        }
        int mid = -1, check = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                mid = i;
                check++;
            }
        }

        if (check >= 2) bw.write("I'm Sorry Hansoo\n");
        else {
            StringBuilder front = new StringBuilder();
            StringBuilder back = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0) continue;
                for (int j = 0; j < cnt[i] / 2; j++) {
                    front.append((char) (i + 'A'));
                }
            }
            back.append(front);
            back.reverse();
            if (mid != -1) {
                front.append((char) (mid + 'A'));
            }
            front.append(back);
            bw.write(front.toString());
        }
        bw.flush();
        bw.close();
    }
}