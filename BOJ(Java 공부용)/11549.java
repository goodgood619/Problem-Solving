import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int t = Integer.parseInt(input[0]);
        String[] input2 = br.readLine().split(" ");
        int cnt=0;
        for(int i=0;i<input2.length;i++) {
            int tea = Integer.parseInt(input2[i]);
            if(t == tea) cnt++;
        }
        System.out.println(cnt);
    }

}