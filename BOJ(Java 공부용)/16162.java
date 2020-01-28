import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[1]);
        int d = Integer.parseInt(input[2]);
        String[] input2 = br.readLine().split(" ");
        int cur = a;
        int cnt = 0;
        for(int i=0;i<input2.length;i++) {
            if(cur == Integer.parseInt(input2[i])) {
                cnt++;
                cur += d;
            }
        }
        bw.write(cnt+"\n");
        bw.flush();
        bw.close();
    }
}