import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = 1;
        while(true) {
            int n = Integer.parseInt(br.readLine());
            if(n == 0) break;
            int n1 = n*3, n2 = 0;
            boolean check = false;
            if(n1 %2 == 0) {
                check = false;
                n2 = n1 /2;
            } else{
                check = true;
                n2 = (n1+1) / 2;
            }
            int n3 = 3 *n2, n4 = n3/9;
            if(check) bw.write(tc+". "+"odd "+n4+"\n");
            else bw.write(tc+". "+"even "+n4+"\n");
            tc++;
        }
        bw.flush();
        bw.close();
    }
}