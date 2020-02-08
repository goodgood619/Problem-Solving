import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] check = new int[26];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                check[s.charAt(i) - 97]++;
            } else check[s.charAt(i) - 65]++;
        }
        int max = 0;
        char c = 0;
        for (int i = 0; i < 26; i++) {
            if (max < check[i]) {
                max = check[i];
                c = (char) (i + 65);
            }
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (max == check[i]) {
                cnt++;
            }
        }
        if (cnt >= 2) System.out.println("?");
        else System.out.println(c);
    }
}