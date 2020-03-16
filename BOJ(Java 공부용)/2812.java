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
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        String s = br.readLine();
        Deque<Character> stack = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            char here = s.charAt(i);
            if (stack.isEmpty() || k == 0) {
                stack.addFirst(here);
                continue;
            }
            while (!stack.isEmpty() && stack.peekFirst() < here && k > 0) {
                stack.pollFirst();
                k--;
            }
            stack.addFirst(here);
        }
        while (k > 0) {
            stack.pollFirst();
            k--;
        }
        while (!stack.isEmpty()) {
            bw.write(stack.peekLast());
            stack.pollLast();
        }
        bw.flush();
        bw.close();
    }
}