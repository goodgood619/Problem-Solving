import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().split(" ")[0]);
        for (int i = 0; i < t; i++) {
            int[] check = new int[26];
            int[] check2 = new int[26];
            for(int j=0;j<26;j++) {
                check[j] = 0;
                check2[j] = 0;
            }
            String[] input2 = br.readLine().split( " ");
            if(input2[0].length() != input2[1].length()) {
                System.out.println("Impossible");
                continue;
            }
            for(int j=0;j<input2[0].length();j++) {
                check[input2[0].charAt(j)-'a']++;
                check2[input2[1].charAt(j)-'a']++;
            }
            boolean pos = true;
            for(int j=0;j<26;j++) {
                if(check[j]==check2[j]) continue;
                else {
                    pos = false;
                    break;
                }
            }
            System.out.println(pos?"Possible":"Impossible");

        }
    }
}