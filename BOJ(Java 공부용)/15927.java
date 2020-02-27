import java.io.*;
import java.util.HashSet;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        HashSet<Character> set = new HashSet<>();
        boolean check = false;
        for (int i = 0, j = s.length() - 1; i <= j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) {
                check = true;
                break;
            }
        }
        if (check) System.out.println(s.length());
        else {
            for (int i = 0; i < s.length(); i++) {
                set.add(s.charAt(i));
            }
            if (set.size() == 1) System.out.println(-1);
            else System.out.println(s.length() - 1);
        }
    }
}