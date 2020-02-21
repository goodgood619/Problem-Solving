import java.io.*;
import java.util.ArrayList;
import static java.lang.StrictMath.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[8000001];
        int cnt = 0;
        for (int i = 2; i <= sqrt(8000000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 8000000; j += i) {
                if (notprime[j]) continue;
                notprime[j] = true;
                cnt++;
            }
        }
        int[] isprime = new int[8000001-cnt];
        int idx=0;
        for(int i=2;i<8000000;i++) {
            if(!notprime[i]) isprime[idx++]=i;
        }
        int k = Integer.parseInt(br.readLine());
        k--;
        System.out.println(isprime[k]);
    }
}