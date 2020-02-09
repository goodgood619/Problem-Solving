import java.io.*;
import java.util.*;

import static java.lang.Integer.min;
import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int min = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][n];
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 1; i < n; i++) {
            go(0, 0, i, board, visited);
        }
        bw.write(min + " ");
        bw.flush();
        bw.close();
    }

    private static void go(int index, int cnt, int depth, int[][] board, boolean[] visited) {
        if (cnt == depth) {
            ArrayList<Integer> home = new ArrayList<>();
            ArrayList<Integer> away = new ArrayList<>();
            for (int i = 0; i < visited.length; i++) {
                if (visited[i]) {
                    home.add(i);
                } else {
                    away.add(i);
                }
            }
            int hometotal = 0, awaytotal = 0;
            for (int i = 0; i < home.size(); i++) {
                for (int j = 0; j < home.size(); j++) {
                    int here = home.get(i), next = home.get(j);
                    hometotal += board[here][next];
                }
            }
            for (int i = 0; i < away.size(); i++) {
                for (int j = 0; j < away.size(); j++) {
                    int here = away.get(i), next = away.get(j);
                    awaytotal += board[here][next];
                }
            }
            min = min(min, abs(hometotal - awaytotal));
            return;
        }
        for (int i = index; i < visited.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                go(i + 1, cnt + 1, depth, board, visited);
                visited[i] = false;
            }
        }
    }
}