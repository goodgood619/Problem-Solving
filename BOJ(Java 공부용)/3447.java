import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        while ((s = br.readLine()) != null) {
            StringBuilder sb = new StringBuilder();
            while (s.contains("BUG")) {
                s = s.replace("BUG", "");
            }
            sb.append(s);
            bw.write(sb.toString() + "\n");
        }
        bw.flush();
        bw.close();
    }
}