import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static int score = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<p> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int[] arr = new int[5];
            boolean[] visited = new boolean[5];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                arr[j] = Integer.parseInt(st.nextToken());
            }
            go(0, 0, 3, arr, visited);
            v.add(new p(i + 1, score));
            score = 0;
        }
        v.sort((a, b) -> {
            if (a.score > b.score) return -1;
            else if (a.score < b.score) return 1;
            else {
                if (a.index > b.index) return -1;
                else if (a.index < b.index) return 1;
                else return 0;
            }
        });
        System.out.println(v.get(0).index);
    }

    private static void go(int index, int cnt, int depth, int[] arr, boolean[] visited) {
        if (cnt == depth) {
            int sum = 0;
            for (int i = 0; i < arr.length; i++) {
                if (visited[i]) sum += arr[i];
            }
            score = max(score, sum % 10);
            return;
        }
        for (int i = index; i < arr.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                go(i + 1, cnt + 1, depth, arr, visited);
                visited[i] = false;
            }
        }
    }

    private static class p {
        int index, score;

        private p(int index, int score) {
            this.index = index;
            this.score = score;
        }
    }
}