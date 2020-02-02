import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int cnt = 0;
        if(n<100) cnt += n;
        else {
            cnt += 99;
            for(int i=100;i<=n;i++) {
                cnt += go(i);
            }
        }
        System.out.println(cnt);
    }
    private static int go(int num) {
        if(num<=999) {
            int first = (num / 100)-((num / 10)%10);
            int second = ((num / 10) % 10) - (num % 10);
            if (first == second) return 1;
            else return 0;
        }
        else if(num == 1000) return 0;
        return num;
    }
}