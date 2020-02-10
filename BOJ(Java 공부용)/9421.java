import java.io.*;
import java.util.*;
import static java.lang.StrictMath.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[1000001];
        for (int i = 2; i <= sqrt(1000000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 1000000; j += i) {
                notprime[j] = true;
            }
        }
        int n = Integer.parseInt(br.readLine());
        for (int i = 2; i <= n; i++) {
            if (notprime[i]) continue;
            int temp = i;
            boolean check = false;
            HashMap<Integer, Integer> map = new HashMap<>();
            while (true) {
                int sum = 0;
                String s = String.valueOf(temp);
                for (int j = 0; j < s.length(); j++) {
                    sum += (s.charAt(j) - '0') * (s.charAt(j) - '0');
                }
                if (sum == 1) {
                    check = true;
                    break;
                }
                if (map.get(sum) == null) {
                    map.put(sum, 1);
                    temp = sum;
                } else break;
            }
            if (check) bw.write(i + "\n");
        }
        bw.flush();
        bw.close();
    }
}