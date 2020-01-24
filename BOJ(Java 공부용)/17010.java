import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int t = Integer.parseInt(input[0]);
        for(int i=0;i<t;i++) {
            String[] input2 = br.readLine().split(" ");
            for(int j=0;j<Integer.parseInt(input2[0]);j++) {
                bw.write(input2[1]);
            }
            bw.write("\n");
            bw.flush();
        }
    }
}