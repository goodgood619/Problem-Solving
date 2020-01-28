import java.io.*;
import static java.lang.Integer.max;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int min = 1000000;
        int max = 0;
        String[] input = br.readLine().split(" ");
        for(int i=0;i<input.length;i++) {
            min = min(min,Integer.parseInt(input[i]));
            max = max(max,Integer.parseInt(input[i]));
        }
        bw.write(min*max+"\n");
        bw.flush();
        bw.close();
    }
}