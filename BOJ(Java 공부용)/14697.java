import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b= Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
        for (int i = 0; i*a <= d; i++) {
            for (int j = 0; j*b <= d; j++) {
                for (int k = 0; k*c <= d; k++) {
                    if (a*i + b * j + k * c == d) {
                        System.out.println(1);
                        return;
                    }
                }
            }
        }
        System.out.println(0);
    }
}