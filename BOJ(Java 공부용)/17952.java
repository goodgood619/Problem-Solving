import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Deque<p> stack = new ArrayDeque<>();
        int n = Integer.parseInt(br.readLine()), sum = 0;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int what = Integer.parseInt(st.nextToken());
            if (what == 0) {
                if (stack.isEmpty()) continue;
                p res = stack.peek();
                res.minute--;
                if (res.minute == 0) {
                    stack.pollFirst();
                    sum += res.score;
                } else {
                    stack.pollFirst();
                    stack.addFirst(new p(res.score, res.minute));
                }
            } else {
                int score = Integer.parseInt(st.nextToken()), minute = Integer.parseInt(st.nextToken());
                minute--;
                if (minute == 0) {
                    sum += score;
                } else {
                    stack.addFirst(new p(score, minute));
                }
            }
        }
        bw.write(sum + "");
        bw.flush();
        bw.close();
    }
}

class p {
    int score, minute;

    p(int score, int minute) {
        this.score = score;
        this.minute = minute;
    }
}