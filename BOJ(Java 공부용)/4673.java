import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 1; i <= 10000; i++) {
            boolean check = false;
            for (int j = 1; j < i; j++) {
                int sum = j;
                String s = String.valueOf(j);
                for (int k = 0; k < s.length(); k++) sum += (s.charAt(k) - '0');
                if (sum == i) {
                    check = true;
                    break;
                }
            }
            if (!check) bw.write(i+"\n");
        }
        bw.flush();
        bw.close();
    }
}