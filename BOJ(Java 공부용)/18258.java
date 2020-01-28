import java.io.*;
import java.util.ArrayDeque;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        ArrayDeque<Integer> q = new ArrayDeque<>();
        for(int i=0;i<n;i++) {
            String[] input2 = br.readLine().split(" ");
            String s = input2[0];
            if(s.equals("push")) {
                q.add(Integer.parseInt(input2[1]));
            }
            else if(s.equals("front")) {
                if(q.isEmpty()) {
                    bw.write("-1\n");
                }
                else bw.write(q.peek()+"\n");
            }
            else if(s.equals("pop")) {
                if(q.isEmpty()) {
                    bw.write("-1\n");
                }
                else {
                    bw.write(q.poll()+"\n");
                }
            }
            else if(s.equals("size")) {
                bw.write(q.size()+"\n");
            }
            else if(s.equals("empty")) {
                if(q.isEmpty()) {
                    bw.write("1\n");
                }
                else bw.write("0\n");
            }
            else {
                if(q.isEmpty()) {
                    bw.write("-1\n");
                }
                else bw.write(q.peekLast()+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
}