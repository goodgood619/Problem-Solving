import java.io.*;
import java.util.StringTokenizer;

import static java.lang.StrictMath.pow;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] cnt = new int[1000000];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), p = Integer.parseInt(st.nextToken());
        dfs(a, p, cnt);
        int ans = 0;
        for (int i = 1; i < 1000000; i++) {
            if (cnt[i] == 1) ans++;
        }
        System.out.println(ans);
    }

    private static void dfs(int a, int p, int[] cnt) {
        cnt[a]++;
        int value = 0;
        while (a != 0) {
            value += pow(a % 10, p);
            a /= 10;
        }
        if (cnt[value] < 2) dfs(value, p, cnt);
    }
}