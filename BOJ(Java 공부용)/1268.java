import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n + 1][6];
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 5; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        List<p> v = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            int samecnt = 0;
            boolean[] visited = new boolean[n + 1];
            for (int k = 1; k <= 5; k++) {
                for (int j = 1; j <= n; j++) {
                    if (j == i || visited[j] || arr[j][k] != arr[i][k]) continue;
                    samecnt++;
                    visited[j] = true;
                }
            }
            v.add(new p(i, samecnt));
        }
        v.sort((a, b) -> {
            if (a.cnt > b.cnt) return -1;
            else if (a.cnt < b.cnt) return 1;
            else {
                if (a.idx < b.idx) return -1;
                else if (a.idx > b.idx) return 1;
                else return 0;
            }
        });
        bw.write(v.get(0).idx + "");
        bw.flush();
        bw.close();
    }
}

class p {
    int idx, cnt;

    p(int idx, int cnt) {
        this.idx = idx;
        this.cnt = cnt;
    }
}