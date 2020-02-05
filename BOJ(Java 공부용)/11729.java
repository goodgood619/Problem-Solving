import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int cnt = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
            hanoi(n, 1, 2, 3);
            System.out.println(cnt);
            hanoi2(n,1,2,3);
            bw.flush();
            bw.close();
    }
    private static void hanoi(int n, int st, int by, int to) {
        if (n == 1){
            cnt++;
            return;
        }
        else{
            hanoi(n - 1, st, to, by);
            cnt++;
            hanoi(n - 1, by, st, to);
        }
    }
    private static void hanoi2(int n, int st, int by, int to) throws IOException {
        if (n == 1) {
            bw.write(st+" "+to+"\n");
            return;
        }
        else {
            hanoi2(n - 1, st, to, by);
            bw.write(st+" " +to+"\n");
            hanoi2(n - 1, by, st, to);
        }
    }
}