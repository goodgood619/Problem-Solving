import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        long sum = 0;
        for(int i=0;i<input[0].length();i++) {
            for(int j=0;j<input[1].length();j++) {
                sum += (input[0].charAt(i)-'0')* (input[1].charAt(j)-'0');
            }
        }
        System.out.println(sum);
    }
}