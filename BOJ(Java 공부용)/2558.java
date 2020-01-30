import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n =Integer.parseInt(br.readLine().split(" ")[0]);
        int m = Integer.parseInt(br.readLine().split(" ")[0]);
        System.out.println(n+m);
    }
}