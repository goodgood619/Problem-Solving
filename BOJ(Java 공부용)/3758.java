import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken()), myt = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
            int[] total = new int[n + 1];
            int[][] bestscore = new int[n + 1][k + 1];
            int[] cnt = new int[n + 1];
            int[] lateapply = new int[n + 1];
            ArrayList<p> v = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int teamnum = Integer.parseInt(st.nextToken()), problemnum = Integer.parseInt(st.nextToken()), score = Integer.parseInt(st.nextToken());
                bestscore[teamnum][problemnum] = max(bestscore[teamnum][problemnum], score);
                cnt[teamnum]++;
                lateapply[teamnum] = max(lateapply[teamnum], i + 1);
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= k; j++) {
                    total[i] += bestscore[i][j];
                }
            }
            for (int i = 1; i <= n; i++) {
                v.add(new p(i, total[i], cnt[i], lateapply[i]));
            }
            v.sort((a, b) -> {
                if (a.score > b.score) return -1;
                else if (a.score < b.score) return 1;
                else {
                    if (a.cnt < b.cnt) return -1;
                    else if (a.cnt > b.cnt) return 1;
                    else {
                        if (a.time < b.time) return -1;
                        else if (a.time > b.time) return 1;
                        else return 0;
                    }
                }
            });
            for (int i = 0; i < v.size(); i++) {
                if (myt == v.get(i).teamnum) {
                    System.out.println(i + 1);
                    break;
                }
            }
        }

    }

    private static class p {
        int teamnum, score, cnt, time;

        private p(int teamnum, int score, int cnt, int time) {
            this.teamnum = teamnum;
            this.score = score;
            this.cnt = cnt;
            this.time = time;
        }
    }
}