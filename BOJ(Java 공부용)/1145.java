import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[5];
        for (int i = 0; i < 5; i++) arr[i] = Integer.parseInt(st.nextToken());
        for (int i = 1; ; i++) {
            int c = 0;
            for (int j = 0; j < 5; j++) {
                if (i % arr[j] == 0) c++;
            }
            if (c >= 3) {
                System.out.println(i);
                return;
            }
        }
    }
}