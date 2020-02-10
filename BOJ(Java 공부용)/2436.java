import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Long.max;
import static java.lang.Long.min;
import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        m /= n;

        long ans = (long) 1e18,one = 1, two = 100000000,ans1=0,ans2=0;
        for (long i = 1; i <= sqrt(m); i++) {
            if (m % i == 0) {
                    one = max(one,n * i);
                    two = min(two,n * m / i);
                    int what=gcd(one,two);
                    if(what== n && ans > one+two) {
                        ans = one+two;
                        ans1=one;
                        ans2=two;
                    }
                }
        }
        System.out.println(ans1 + " " + ans2);
    }
    private static int gcd(long a,long  b) {
        if(a%b==0) return (int)b;
        return gcd(b%a,a);
    }
}