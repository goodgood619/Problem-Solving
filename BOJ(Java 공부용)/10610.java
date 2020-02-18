import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] check = new int[10];
        for (int i = 0; i < s.length(); i++) {
            check[s.charAt(i) - '0']++;
        }
        if (check[0] == 0) System.out.println(-1);
        else {
            int sum = 0;
            for (int i = 0; i < 10; i++) {
                sum += i * check[i];
            }
            if (sum % 3 != 0) System.out.println(-1);
            else {
                StringBuilder sb = new StringBuilder();
                for (int i = 9; i >= 0; i--) {
                    while (check[i] != 0) {
                        sb.append(i);
                        check[i]--;
                    }
                }
                bw.write(sb.toString());
                bw.flush();
                bw.close();
            }
        }
    }

}