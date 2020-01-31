import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        double a = Double.parseDouble(input[0]);
        double b = Double.parseDouble(input[1]);
        double v = Double.parseDouble(input[2]);
        double day = (v-a)/(a-b);
        double rest = day-(int)day;
        if(rest != 0) {
            System.out.println((int)day+2);
        } else {
            System.out.println((int)day+1);
        }
    }
}