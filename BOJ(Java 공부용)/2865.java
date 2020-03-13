import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        Map<Integer, Double> map = new HashMap<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int num = Integer.parseInt(st.nextToken());
                double score = Double.parseDouble(st.nextToken());
                if (map.get(num) == null) map.put(num, score);
                else {
                    double value = map.get(num);
                    if (value < score) {
                        map.remove(num);
                        map.put(num, score);
                    }
                }
            }
        }
        List<p> v = new ArrayList<>();
        for (Integer a : map.keySet()) {
            v.add(new p(a, map.get(a)));
        }
        v.sort((a, b) -> {
            if (a.score > b.score) return -1;
            else if (a.score < b.score) return 1;
            else return 0;
        });
        double sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v.get(i).score;
            k--;
            if (k == 0) break;
        }
        System.out.printf("%.1f", sum);
    }

    private static class p {
        int idx;
        double score;

        private p(int idx, double score) {
            this.idx = idx;
            this.score = score;
        }
    }
}