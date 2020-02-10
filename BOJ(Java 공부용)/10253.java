import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            for (int i = 2; ; i++) {
                if(a==1) {
                    bw.write(b+"\n");
                    break;
                }
                if (a * i - b < 0) continue;
                else if (a * i - b == 0) {
                    bw.write(i + "\n");
                    break;
                } else {
                    int y = i * b;
                    int x = a * i - b;
                    b = y;
                    a = x;
                    int g = gcd(a, b);
                    if (g != 1) {
                        b /= g;
                        a /= g;
                    }
                }
            }
        }
        bw.flush();
        bw.close();
    }

    private static int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b % a, a);
    }

}