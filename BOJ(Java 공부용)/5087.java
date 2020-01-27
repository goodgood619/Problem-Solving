import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[]gox = {0,1,-1,0};
    static int[]goy = {1,0,0,-1};
    static double win = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String[] input = br.readLine().split(" ");
            if(input[0].equals("#")) break;
            int c = 0, d = 0;
            for(int i=0;i<input.length;i++) {
                if(input[i].charAt(0)=='*') break;
                else if(input[i].charAt(0)=='A' || (input[i].charAt(0)-'0')%2 == 1) c++;
                else d++;
            }
            if(c>d) bw.write("Cheryl\n");
            else if(c<d) bw.write("Tania\n");
            else bw.write("Draw\n");
        }
        bw.flush();
        bw.close();
    }
}