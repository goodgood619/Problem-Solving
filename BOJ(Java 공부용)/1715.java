import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=1;i<=n;i++) {
            pq.add(Integer.parseInt(br.readLine()));
        }
        int sum = 0;
        while(true) {
            if(pq.size() == 1) break;
            int top1 = pq.peek();
            pq.poll();
            int top2 = pq.peek();
            pq.poll();
            pq.add(top1+top2);
            sum += (top1+ top2);
        }
        System.out.println(sum);
    }
}