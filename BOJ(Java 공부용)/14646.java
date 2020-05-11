import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        n *= 2;
        int[] arr = new int[100000];
        int cur = 0, max = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            num--;
            if (arr[num] == 0) cur++;
            else if (arr[num] == 1) cur--;
            arr[num]++;
            max = Math.max(max, cur);
        }
        bw.write(max + "");
        bw.flush();
        bw.close();
    }
}