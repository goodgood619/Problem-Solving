import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        if (s.length() == 1) {
            System.out.println("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
            return;
        }
        int diff = s.charAt(1) - s.charAt(0);
        for (int i = 1; i < s.length() - 1; i++) {
            if (diff != (int) s.charAt(i + 1) - s.charAt(i)) {
                System.out.println("흥칫뿡!! <(￣ ﹌ ￣)>");
                return;
            }
        }
        System.out.println("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
    }
}