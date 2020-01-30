import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        int cnt = 0;
        boolean[] check = new boolean[n+1];
        for(int i=2;i<=n;i++) {
            if(check[i]) continue;
            for(int j=i;j<=n;j+=i) {
                if(check[j]) continue;
                check[j] = true;
                cnt++;
                if(cnt == k) {
                    bw.write(j + "\n");
                    bw.flush();
                    bw.close();
                    return;
                }
            }
        }
    }
}