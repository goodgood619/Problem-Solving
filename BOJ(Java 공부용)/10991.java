import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int r = 1;
        for (int i = n; i>=1; i--) {
            for (int j = i - 1; j >0; j--)
                bw.write(" ");
            for (int k = 1; k <= 2 * r - 1; k++) {
                if (k % 2 == 0)
                    bw.write(" ");
                else
                    bw.write("*");
            }
            r++;
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}