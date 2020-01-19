import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        Deque<Integer> stack = new ArrayDeque<>();
        for(int i=0;i<n;i++) {
            String[] s = br.readLine().split(" ");
            if(s[0].equals("push")) {
                int num = Integer.parseInt(s[1]);
                stack.add(num);
            } else if(s[0].equals("top")) {
                if(stack.isEmpty()) {
                    bw.write("-1\n");
                    bw.flush();
                } else {
                    bw.write(String.valueOf(stack.peekLast())+"\n");
                    bw.flush();
                }
            } else if(s[0].equals("size")) {
                bw.write(String.valueOf(stack.size()) +"\n");
                bw.flush();
            } else if(s[0].equals("empty")) {
                if(stack.isEmpty()) {
                    bw.write("1\n");
                    bw.flush();
                } else {
                    bw.write("0\n");
                    bw.flush();
                }
            } else if(s[0].equals("pop")) {
                if(stack.isEmpty()) {
                    bw.write("-1\n");
                    bw.flush();
                } else {
                    bw.write(String.valueOf(stack.pollLast())+"\n");
                    bw.flush();
                }
            }
        }
    }
}