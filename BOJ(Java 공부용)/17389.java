import java.io.*;
import java.util.Arrays;

import static java.lang.Long.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        int bonus = 0;
        int earn = 0;
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i) == 'O') {
                earn += (i+1);
                if(bonus >0) {
                    earn += bonus;
                    bonus++;
                }
                else bonus = 1;
            } else{
                bonus = 0;
            }
        }
        bw.write(String.valueOf(earn));
        bw.flush();
        bw.close();
    }
}