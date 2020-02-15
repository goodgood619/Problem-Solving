import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String s = br.readLine();
            if (s.equals("#")) break;
            int sum = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == ' ') continue;
                sum += (i + 1) * (s.charAt(i) - 'A' + 1);
            }
            bw.write(sum + "\n");
        }
        bw.flush();
        bw.close();
    }
}