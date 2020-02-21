import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        ArrayDeque<Integer> stack = new ArrayDeque<>();
        stack.add(0);
        int max = n, k = 1;
        ArrayList<Character> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            while (num != stack.peekLast() && k <= max) {
                stack.add(k++);
                v.add('+');
            }
            while (num == stack.peekLast()) {
                stack.pollLast();
                v.add('-');
            }
        }
        if (stack.peekLast() == 0) {
            for (int i = 0; i < v.size(); i++) {
                bw.write(v.get(i) + "\n");
            }
            bw.flush();
            bw.close();
        } else System.out.println("NO");
    }
}