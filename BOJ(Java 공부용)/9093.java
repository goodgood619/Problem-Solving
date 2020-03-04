import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1, 1, 1, -1, -1};
    static int[] goy = {1, -1, 0, 0, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] input = br.readLine().split(" ");
            for (int i = 0; i < input.length; i++) {
                String s = input[i];
                for (int j = s.length() - 1; j >= 0; j--) bw.write(s.charAt(j));
                bw.write(" ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}