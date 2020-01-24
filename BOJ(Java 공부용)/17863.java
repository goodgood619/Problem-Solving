import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        if(input[0].charAt(0)=='5' && input[0].charAt(1)=='5' && input[0].charAt(2)=='5')
        {
            System.out.println("YES");
        }
        else System.out.println("NO");
    }
}
