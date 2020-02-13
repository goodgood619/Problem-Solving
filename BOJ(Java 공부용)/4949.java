import java.io.*;
import java.util.ArrayDeque;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String s = br.readLine();
            if (s.equals(".")) break;
            boolean no = false;
            ArrayDeque<Character> stack = new ArrayDeque<>();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '(' || c == '[') stack.add(c);
                else if (c == ')' || c == ']') {
                    if (stack.isEmpty()) {
                        no = true;
                        break;
                    }
                    if (c == ')' && stack.peekLast() != '(') {
                        no = true;
                        break;
                    }
                    if (c == ']' && stack.peekLast() != '[') {
                        no = true;
                        break;
                    }
                    stack.pollLast();
                }
            }
           bw.write(no || !stack.isEmpty()? "no\n" : "yes\n");
        }
        bw.flush();
        bw.close();
    }
}