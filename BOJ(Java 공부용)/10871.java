import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String arr[] = br.readLine().split(" ");
        int n= Integer.parseInt(arr[0]),x = Integer.parseInt(arr[1]);
        String s[] = br.readLine().split(" ");
        int sum =0;
        for(int i=0;i<s.length;i++) {
            int num = Integer.parseInt(s[i]);
            if(num<x) {
                bw.write(String.valueOf(num)+" ");
                bw.flush();
            }
        }
    }
}