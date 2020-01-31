import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int p = n;
        int[] arr = {64,32,16,8,4,2,1};
        int cnt = 0;
        while(p != 0) {
            for(int i=0;i<7;i++) {
                if(p>=arr[i]) {
                    p -= arr[i];
                    cnt++;
                    break;
                }
            }
        }
        System.out.println(cnt);
    }
}