import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), q = Integer.parseInt(st.nextToken());
        int[] totaltime = new int[n + 1];
        int[] totalcnt = new int[n + 1];
        int[][] failcnt = new int[n + 1][m + 1];
        boolean[][] check = new boolean[n + 1][m + 1];
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken()), team = Integer.parseInt(st.nextToken()), problem = Integer.parseInt(st.nextToken());
            String s = st.nextToken();
            if (s.equals("AC")) {
                if (check[team][problem]) continue;
                totalcnt[team]++;
                check[team][problem] = true;
                totaltime[team] += time + failcnt[team][problem] * 20;
            } else {
                failcnt[team][problem]++;
            }
        }

        ArrayList<p> v = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            v.add(new p(totalcnt[i], totaltime[i], i));
        }
        v.sort((a, b) -> {
            if (a.cnt > b.cnt) return -1;
            else if (a.cnt < b.cnt) return 1;
            else {
                if (a.time < b.time) return -1;
                else if (a.time > b.time) return 1;
                else {
                    if (a.index < b.index) return -1;
                    else if (a.index > b.index) return 1;
                    else return 0;
                }
            }
        });
        for (int i = 0; i < v.size(); i++) {
            bw.write(v.get(i).index + " " + v.get(i).cnt + " " + v.get(i).time + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static class p {
        int cnt, time, index;

        private p(int cnt, int time, int index) {
            this.cnt = cnt;
            this.time = time;
            this.index = index;
        }
    }
}