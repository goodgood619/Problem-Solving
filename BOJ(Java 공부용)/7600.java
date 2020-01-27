import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String[] input = br.readLine().split(" ");
            if(input[0].equals("#")) break;
            int[] check = new int[26];
            for(int i=0;i<26;i++) check[i] = 0;
            for(int i=0;i<input.length;i++) {
                for(int j=0;j<input[i].length();j++) {
                    if(input[i].charAt(j)>='A' && input[i].charAt(j)<='Z') {
                        check[input[i].charAt(j)-'A']++;
                    }
                    else if(input[i].charAt(j)>='a' && input[i].charAt(j)<='z') {
                        check[input[i].charAt(j)-'a']++;
                    }
                }
            }
            int cnt = 0;
            for(int i=0;i<26;i++) {
                if(check[i]>0) cnt++;
            }
            bw.write(String.valueOf(cnt)+"\n");
        }
        bw.flush();
        bw.close();
    }
}