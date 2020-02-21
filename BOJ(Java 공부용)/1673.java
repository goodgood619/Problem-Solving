import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        while ((s = br.readLine()) != null) {
            String[] input = s.split(" ");
            long n = Long.parseLong(input[0]), k = Long.parseLong(input[1]), sum = n;
            while (true) {
                long mok = n / k;
                long mod = n % k;
                sum += mok;
                n = mok + mod;
                if (n < k) break;
            }
            bw.write(sum + "\n");
        }
        bw.flush();
        bw.close();
    }
}