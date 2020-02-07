import java.io.*;
import static java.lang.Math.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[1501];
        for (int i = 2; i <= sqrt(1500); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 1500; j += i) {
                notprime[j] = true;
            }
        }
        String s = br.readLine();
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') cnt += (s.charAt(i) - 96);
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') cnt += (s.charAt(i) - 38);
        }
        bw.write(notprime[cnt] ? "It is not a prime word.\n" : "It is a prime word.\n");
        bw.flush();
        bw.close();
    }
}