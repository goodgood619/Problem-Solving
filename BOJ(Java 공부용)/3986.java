import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken()), cnt = 0;
        while (t-- > 0) {
            String s = br.readLine();
            ArrayDeque<Character> stack = new ArrayDeque<>();
            stack.add(s.charAt(0));
            for (int i = 1; i < s.length(); i++) {
                if (stack.isEmpty()) {
                    stack.add(s.charAt(i));
                } else if (s.charAt(i) == stack.peekLast()) {
                    stack.pollLast();
                } else if (s.charAt(i) != stack.peekLast()) {
                    stack.add(s.charAt(i));
                }
            }
            if (stack.isEmpty()) cnt++;
        }
        System.out.println(cnt);
    }
}