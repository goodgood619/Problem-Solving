import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);
        int w = Integer.parseInt(input[2]);
        int h = Integer.parseInt(input[3]);
        int a = w - x;
        int b = h - y;
        if(a>x) {
            if(b>y) {
                if(x>y) System.out.println(y);
                else System.out.println(x);
            }
            else {
                if(x>b) System.out.println(b);
                else System.out.println(x);
            }
        }
        else {
            if(b>y) {
                if(a>y) System.out.println(y);
                else System.out.println(a);
            }
            else {
                if(a>b) System.out.println(b);
                else System.out.println(a);
            }
        }
    }
}