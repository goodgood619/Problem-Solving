import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int ans = input.length;
        for(int i=0;i<input.length;i++) {
           if(input[i].equals("")) ans--;
        }
        System.out.println(ans);
    }
}