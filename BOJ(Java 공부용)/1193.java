import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int sum = 0, plus = 1;
        while (n > sum) {
            sum += plus;
            plus++;
        }
        plus--;
        //위에서 아래로
        if (plus % 2 == 1) {
            int a = 1, b = plus;
            while (n != sum) {
                a++;
                b--;
                sum--;
            }
            bw.write(a + "/" + b + " ");
        }
        //아래서 위로
        else {
            int a = plus, b = 1;
            while (n != sum) {
                a--;
                b++;
                sum--;
            }
            bw.write(a + "/" + b + " ");
        }
        bw.flush();
        bw.close();
    }
}