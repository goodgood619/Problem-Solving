import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        boolean[] visited = new boolean[m];
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        go(0, 0, 3, visited, board, v, d, n, m);
        System.out.println(ans);
    }

    private static void go(int index, int cnt, int depth, boolean[] visited, int[][] board, ArrayList<Integer> v, int d, int n, int m) {
        if (cnt == depth) {
            int[][] tempboard = new int[n][m];
            int total = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    tempboard[i][j] = board[i][j];
                }
            }
            while (true) {
                ArrayList<p> attack = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (tempboard[i][j] == 1) {
                            for (int k = 0; k < v.size(); k++) {
                                if (abs(v.get(k) - j) + abs(n - i) <= d) {
                                    attack.add(new p(i, j, abs(v.get(k) - j) + abs(n - i), k));
                                }
                            }
                        }
                    }
                }
                attack.sort((a, b) -> {
                    if (a.dist < b.dist) return -1;
                    else if (a.dist > b.dist) return 1;
                    else {
                        if (a.y < b.y) return -1;
                        else if (a.y > b.y) return 1;
                        else {
                            if (a.x < b.x) return -1;
                            else if (a.x > b.x) return 1;
                            else return 0;
                        }
                    }
                });

                HashMap<Integer, Integer> map = new HashMap<>();
                for (int i = 0; i < attack.size(); i++) {
                    int x = attack.get(i).x, y = attack.get(i).y, who = attack.get(i).who;
                    if (map.get(who) == null) {
                        if (tempboard[x][y] == 0) {
                            map.put(who, 1);
                            continue;
                        }
                        map.put(who, 1);
                        tempboard[x][y] = 0;
                        total++;
                    }
                }
                down(tempboard, n, m);
                if (check(tempboard, n, m)) break;
            }
            ans = max(ans, total);
            return;
        }
        for (int i = index; i < m; i++) {
            if (!visited[i]) {
                visited[i] = true;
                v.add(i);
                go(i + 1, cnt + 1, depth, visited, board, v, d, n, m);
                v.remove(v.size() - 1);
                visited[i] = false;
            }
        }
    }

    private static boolean check(int[][] tempboard, int n, int m) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tempboard[i][j] == 0) cnt++;
            }
        }
        if (cnt == n * m) return true;
        else return false;
    }

    private static void down(int[][] tempboard, int n, int m) {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < m; j++) {
                tempboard[i][j] = tempboard[i - 1][j];
            }
        }
        for (int j = 0; j < m; j++) tempboard[0][j] = 0;
    }

    private static class p {
        int x, y, dist, who;

        private p(int x, int y, int dist, int who) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.who = who;
        }
    }
}