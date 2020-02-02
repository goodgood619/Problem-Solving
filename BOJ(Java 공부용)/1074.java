import java.io.*;
import static java.lang.Math.pow;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static boolean check = false;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), r = Integer.parseInt(input[1]), c = Integer.parseInt(input[2]);
        go(n,r,c,0);
    }
    private static void go(int n,int r,int c,int cnt) {
        if(r == 0 && c==0) {
            System.out.println(cnt);
            System.exit(0);
        }
        int length = (int) pow(2, n - 1);
        if (r < length && c < length) go(n - 1, r, c, cnt);
        if (r < length && c >= length) go(n - 1, r, c - length, cnt + length * length);
        if (r >= length && c < length) go(n - 1, r - length, c, cnt + length * length * 2);
        if (r >= length && c >= length) go(n - 1, r - length, c - length, cnt + length * length * 3);
    }
}