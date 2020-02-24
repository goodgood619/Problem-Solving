import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            int age = Integer.parseInt(st.nextToken()), weight = Integer.parseInt(st.nextToken());
            if (s.equals("#") && age == 0 && weight == 0) break;
            if (age > 17 || weight >= 80) bw.write(s + " " + "Senior\n");
            else bw.write(s + " " + "Junior\n");
        }
        bw.flush();
        bw.close();
    }
}