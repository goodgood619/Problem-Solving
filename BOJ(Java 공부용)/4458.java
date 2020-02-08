import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++) {
            String s= br.readLine();
            StringBuilder sb= new StringBuilder();
            sb.append(s);
            if(sb.charAt(0)>='a'&& sb.charAt(0)<='z') sb.setCharAt(0, (char) (sb.charAt(0)-32));
            bw.write(sb.toString()+"\n");
        }
        bw.flush();
        bw.close();

    }
}