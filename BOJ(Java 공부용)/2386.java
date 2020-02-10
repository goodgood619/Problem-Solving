import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String[] input = br.readLine().split(" ");
            if (input[0].equals("#")) break;
            int cnt = 0;
            for (int i = 1; i < input.length; i++) {
                for (int j = 0; j < input[i].length(); j++) {
                    if (input[0].charAt(0) == input[i].charAt(j)) cnt++;
                    else if (input[0].charAt(0) == input[i].toLowerCase().charAt(j)) cnt++;
                }
            }
            bw.write(input[0].charAt(0) + " " + cnt + "\n");
        }
        bw.flush();
        bw.close();
    }
}