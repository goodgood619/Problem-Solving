import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            int good=0,bad=0;
            for(int j=0;j<input.length;j++) {
                for(int k=0;k<input[j].length();k++) {
                    if(input[j].charAt(k)=='g' || input[j].charAt(k)=='G') good++;
                    else if(input[j].charAt(k)=='b' || input[j].charAt(k)=='B') bad++;
                }
            }
            for(int j=0;j<input.length;j++) {
                bw.write(input[j]+" ");
            }
            bw.write("is ");
            if(good>bad) bw.write("GOOD\n");
            else if(good==bad) bw.write("NEUTRAL\n");
            else bw.write("A BADDY\n");
            bw.flush();
        }
    }
}
