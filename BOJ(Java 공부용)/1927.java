import java.io.*;
import java.util.PriorityQueue;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for(int i=0;i<n;i++) {
            int num = Integer.parseInt(br.readLine().split(" ")[0]);
            if(num == 0) {
                if(!q.isEmpty()) bw.write(q.poll()+"\n");
                else bw.write("0\n");
            }
            else {
                q.add(num);
            }
        }
        bw.flush();
        bw.close();
    }
}