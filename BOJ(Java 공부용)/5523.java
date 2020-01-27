import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[]gox = {0,1,-1,0};
    static int[]goy = {1,0,0,-1};
    static double win = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int a = 0 ,b = 0;
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            if(Integer.parseInt(input[0])<Integer.parseInt(input[1])) b++;
            else if(Integer.parseInt(input[0])>Integer.parseInt(input[1])) a++;
        }
        System.out.println(a+" "+b);
    }
}