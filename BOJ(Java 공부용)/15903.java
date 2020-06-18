import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};
    static int total = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        PriorityQueue<Long> pq = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++) {
            long num = Long.parseLong(st.nextToken());
            pq.add(num);
        }
        for(int i=1;i<=m;i++) {
            long num1 = pq.peek();
            pq.poll();
            long num2 = pq.peek();
            pq.poll();
            long num3 = num1+ num2;
            pq.add(num3);
            pq.add(num3);
        }
        long total = 0;
        while(!pq.isEmpty()) {
            long num = pq.peek();
            total += num;
            pq.poll();
        }
        bw.write(total+"");
        bw.flush();
        bw.close();

    }
}