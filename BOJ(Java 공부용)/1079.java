import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] penalty = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            penalty[i] = Integer.parseInt(st.nextToken());
        }
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int mafia = Integer.parseInt(br.readLine());
        boolean[] visited = new boolean[n];
        // 1: 밤, 0: 낮
        dfs(n % 2 == 0 ? 1 : 0, penalty, board, visited, 0, n, mafia);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void dfs(int time, int[] penalty, int[][] board, boolean[] visited, int ncnt, int rest,int mafia) {

        if (rest == 1 || check(mafia, visited)) {
            ans = Math.max(ans, ncnt);
            if(rest ==1 ) {
                System.out.println(ans);
                System.exit(0);
            }
            return;
        }

        // 밤(아무나죽인다)
        if (time == 1) {
            for (int i = 0; i < visited.length; i++) {
                if (!visited[i] && mafia != i) {
                    visited[i] = true;
                    change(i, penalty, board, visited);
                    dfs(0, penalty, board, visited, ncnt+1, rest - 1,  mafia);
                    back(i, penalty, board, visited);
                    visited[i] = false;
                }
            }
        }
        // 낮(가장 높은 유죄지수를 가진사람을 죽인다)
        else {
            int max = 0;
            for (int i = 0; i < visited.length; i++) {
                if (!visited[i]) {
                    max = Math.max(max, penalty[i]);
                }
            }
            int idx = 0;
            for (int i = 0; i < visited.length; i++) {
                if (max == penalty[i] && !visited[i]) {
                    idx = i;
                    break;
                }
            }
            visited[idx] = true;
            dfs(1, penalty, board, visited, ncnt, rest - 1,  mafia);
            visited[idx] = false;
        }
    }

    private static void change(int die, int[] penalty, int[][] board, boolean[] visited) {
        for (int i = 0; i < penalty.length; i++) {
            if (die != i && !visited[i]) penalty[i] += board[die][i];
        }
    }

    private static void back(int die, int[] penalty, int[][] board, boolean[] visited) {
        for (int i = 0; i < penalty.length; i++) {
            if (die != i && !visited[i]) penalty[i] -= board[die][i];
        }
    }

    private static boolean check(int mafia, boolean[] visited) {
        for (int i = 0; i < visited.length; i++) {
            if (visited[i] && mafia == i) return true;
        }
        return false;
    }
}
