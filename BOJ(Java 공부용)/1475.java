import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] arr = new int[10];
        for(int i=0;i<s.length();i++) {
            arr[s.charAt(i)-'0']++;
        }
        int zerocnt = 0, cnt = 0;
        for(int i=0;zerocnt!= 10;i++) {
            zerocnt = 0;
            for(int j= 0;j<10;j++) {
                if(arr[j]>0) arr[j]--;
                else if(arr[j] == 0 && j==6) {
                    if(arr[9]>0) arr[9]--;
                }
                else if(arr[j]==0 && j==9) {
                    if(arr[6]>0) arr[6]--;
                }
            }
            cnt++;
            for(int k=0;k<10;k++) {
                if(arr[k] == 0) zerocnt++;
            }
        }
        System.out.println(cnt);
    }
}