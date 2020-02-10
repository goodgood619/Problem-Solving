import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        boolean check = false;
        if (n == 1) {
            System.out.println(1);
            return;
        }
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                check = true;
                break;
            }
        }
        if (check) System.out.println(0);
        else System.out.println(1);
    }
}