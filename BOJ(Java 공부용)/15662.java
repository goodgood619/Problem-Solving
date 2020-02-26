import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] topni = new int[n][8];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                topni[i][j] = s.charAt(j) - '0';
            }
        }


        int k = Integer.parseInt(br.readLine());
        for (int i = 0; i < k; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken()), rotate = Integer.parseInt(st.nextToken());
            num--;
            boolean[] visited = new boolean[n];
            ArrayList<p> v = new ArrayList<>();
            dfs(num, topni, rotate, visited, v, n);
            for (int j = 0; j < n; j++) {
                if (visited[j]) {
                    for (int p = 0; p < v.size(); p++) {
                        if (v.get(p).num == j) {
                            if (v.get(p).rotate == -1) left(j, topni);
                            else right(j, topni);
                            break;
                        }
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (topni[i][0] == 1) sum++;
        }
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }

    private static void left(int num, int[][] topni) {
        int[][] temptopni;
        temptopni = topni;
        //7->6, 6->5, 5->4, 4->3, 3->2, 2->1, 1->0, 0->7
        int first = topni[num][0];
        for (int i = 0; i < 7; i++) {
            temptopni[num][i] = topni[num][i + 1];
        }
        temptopni[num][7] = first;
        topni = temptopni;
    }

    private static void right(int num, int[][] topni) {
        int[][] temptopni;
        temptopni = topni;
        int first = topni[num][7];
        for (int i = 7; i > 0; i--) {
            temptopni[num][i] = topni[num][i - 1];
        }
        temptopni[num][0] = first;
        topni = temptopni;
    }

    private static class p {
        int num, rotate;

        private p(int num, int rotate) {
            this.num = num;
            this.rotate = rotate;
        }
    }

    private static void dfs(int num, int[][] topni, int rotate, boolean[] visited, ArrayList<p> v, int n) {
        int leftnum = num - 1, rightnum = num + 1;
        visited[num] = true;
        v.add(new p(num, rotate));
        if (leftnum >= 0 && !visited[leftnum] && topni[leftnum][2] != topni[num][6]) {
            dfs(leftnum, topni, rotate == -1 ? 1 : -1, visited, v, n);
        }
        if (rightnum < n && !visited[rightnum] && topni[rightnum][6] != topni[num][2]) {
            dfs(rightnum, topni, rotate == -1 ? 1 : -1, visited, v, n);
        }
    }
}