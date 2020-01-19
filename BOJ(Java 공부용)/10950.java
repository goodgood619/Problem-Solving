import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t= Integer.parseInt(br.readLine());
        for(int i=0;i<t;i++) {
            String[] arr = br.readLine().split(" ");
            int sum =0;
            for(int j = 0; j < arr.length; j++) {
                sum += Integer.parseInt(arr[j]);
            }
            bw.write(String.valueOf(sum)+"\n");
            bw.flush();
        }
    }
}