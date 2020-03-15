import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        int[] path = new int[n];
        Deque<p> stack = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; i--) {
            if (stack.isEmpty()) {
                stack.addFirst(new p(arr[i], i));
            } else {
                if (arr[i] < stack.peekFirst().num) {
                    stack.addFirst(new p(arr[i], i));
                    continue;
                }
                while (!stack.isEmpty() && arr[i] > stack.peekFirst().num) {
                    path[stack.peekFirst().index] = i + 1;
                    stack.pollFirst();
                }
                stack.addFirst(new p(arr[i], i));
            }
        }

        for (int i = 0; i < n; i++) {
            bw.write(path[i] + " ");
        }

        bw.flush();
        bw.close();
    }

    private static class p {
        int num, index;

        private p(int num, int index) {
            this.num = num;
            this.index = index;
        }
    }
}