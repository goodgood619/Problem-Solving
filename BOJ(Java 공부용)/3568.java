import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(",");
        String[] arr = s[0].split(" ");
        String expression = arr[0];
        bw.write(expression);
        StringBuilder sb = new StringBuilder();
        for(int i=arr[1].length()-1;i>=0;i--) {
            char here = arr[1].charAt(i);
            if(here>='A' && here<='Z' || here>='a' && here<='z') {
                sb.append(here);
            }
            make(here);
        }
        bw.write(" "+sb.reverse().toString()+";\n");

        for(int i=1;i<s.length;i++) {
            String temp = s[i];
            bw.write(expression);
            sb = new StringBuilder();
            for(int j=temp.length()-1;j>=0;j--) {
                char here = temp.charAt(j);
                if(here>='A' && here<='Z' || here>='a' && here<='z') {
                    sb.append(here);
                }
                make(here);
            }
            bw.write(" "+sb.reverse().toString()+";\n");
        }
        bw.flush();
        bw.close();
    }

    private static void make(char here) throws IOException {
        if(here==']') bw.write("[");
        else if(here=='[')bw.write("]");
        else if(here=='&' || here=='*') bw.write(here);
    }
}