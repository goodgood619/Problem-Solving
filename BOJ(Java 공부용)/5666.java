import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String> v = new ArrayList<>();
        String str = "";
        while((str=br.readLine())!=null) {
            v.add(str);
        }
        for(int i=0;i<v.size();i++) {
            String[] input = v.get(i).split(" ");
            double a = Double.parseDouble(input[0]);
            double b = Double.parseDouble(input[1]);
            System.out.printf("%.2f\n",a/b);
        }
    }
}
