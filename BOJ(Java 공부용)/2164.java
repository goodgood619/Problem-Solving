import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n + 1];
        ArrayDeque<Integer> q = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            arr[i] = i;
            q.add(i);
        }
        int cnt = 0;
        boolean flag = false;
        while (cnt != n) {
            if (!flag) {
                if (cnt == n - 1) {
                    System.out.println(q.peek());
                    return;
                }
                q.poll();
                flag = true;
                cnt++;
            } else {
                int front = q.peek();
                q.add(front);
                q.poll();
                flag = false;
            }
        }
    }
}