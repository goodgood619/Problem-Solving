import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int cnt = 0;
        for(int i=1;i<=n;i++) {
            int temp = i;
            while(temp>0) {
                if(temp%10==3 || temp%10==6 || temp%10==9) cnt++;
                temp/=10;
            }
        }
        System.out.println(cnt);
    }
}