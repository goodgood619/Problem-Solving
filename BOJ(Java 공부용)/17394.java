import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[100001];
        for (int i = 2; i <= sqrt(100000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 100000; j += i) notprime[j] = true;
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            boolean ok = false;
            for (int i = a; i <= b; i++) {
                if (!notprime[i]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                bw.write("-1\n");
                continue;
            }
            bw.write(bfs(n, a, b, notprime) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int bfs(int n, int a, int b, boolean[] notprime) {
        Deque<p> q = new ArrayDeque<>();
        q.add(new p(n, 0));
        boolean[] visited = new boolean[1090001];
        visited[n] = true;
        while (!q.isEmpty()) {
            int num = q.peek().num;
            int day = q.peek().day;
            if (num >= a && num <= b && !notprime[num]) {
                return day;
            }
            q.poll();
            int one = num / 2, two = num / 3, three = num + 1, four = num - 1;
            if (one > 0 && !visited[one]) {
                visited[one] = true;
                q.add(new p(one, day + 1));
            }
            if (two > 0 && !visited[two]) {
                visited[two] = true;
                q.add(new p(two, day + 1));
            }
            if (three > 0 && !visited[three]) {
                visited[three] = true;
                q.add(new p(three, day + 1));
            }
            if (four > 0 && !visited[four]) {
                visited[four] = true;
                q.add(new p(four, day + 1));
            }
        }

        return -1;
    }
}

class p {
    int num, day;

    p(int num, int day) {
        this.num = num;
        this.day = day;
    }
}