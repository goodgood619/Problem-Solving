import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), a = Integer.parseInt(input[1]), b = Integer.parseInt(input[2]);
        int cnt = 1;
        while(true) {
            if(a == b) break;
            int amod = a%2, bmod = b%2;
            a/=2;
            b/=2;
            if(amod!=0) a++;
            if(bmod!=0) b++;
            if(a!=b) cnt++;
        }
        System.out.println(cnt);
    }
}