import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int cnt = 0;
        for(int i=1;i<=n;i++) {
            int temp = i, sum =0;
            while(temp>0) {
                sum += temp%10;
                temp/=10;
            }
            if(i%sum ==0) cnt++;
        }
        System.out.println(cnt);
    }
}