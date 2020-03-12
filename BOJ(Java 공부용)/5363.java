import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] input = br.readLine().split(" ");
            for (int i = 2; i < input.length; i++) {
                bw.write(input[i] + " ");
            }
            bw.write(input[0] + " ");
            bw.write(input[1] + " ");
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}