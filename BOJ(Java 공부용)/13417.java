import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            Deque<Character> dq = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                String s = st.nextToken();
                if (dq.isEmpty()) {
                    dq.add(s.charAt(0));
                    continue;
                }
                char c = dq.peekFirst();
                if (c < s.charAt(0)) {
                    dq.addLast(s.charAt(0));
                } else {
                    dq.addFirst(s.charAt(0));
                }
            }
            while (!dq.isEmpty()) {
                bw.write(dq.peekFirst());
                dq.poll();
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}