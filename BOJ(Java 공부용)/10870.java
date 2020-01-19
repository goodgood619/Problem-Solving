import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String arr[] = br.readLine().split(" ");
        int n= Integer.parseInt(arr[0]);
        bw.write(String.valueOf(go(n)));
        bw.flush();
    }

    private static int go(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return go(n-1)+go(n-2);
    }
}