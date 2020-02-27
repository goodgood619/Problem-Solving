import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String s = br.readLine();
            if (s.equals("ENDOFINPUT")) break;
            String text = br.readLine();
            String end = br.readLine();
            for (int i = 0; i < text.length(); i++) {
                if (text.charAt(i) >= 'A' && text.charAt(i) <= 'Z') {
                    int c = (text.charAt(i) - 'A' + 21) % 26;
                    bw.write((char) (c + 65));
                } else bw.write(text.charAt(i));
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}