import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1, 1, 1, -1, -1};
    static int[] goy = {1, -1, 0, 0, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s = br.readLine();
            StringBuilder sb = new StringBuilder();
            int[] check = new int[26];
            for (int i = 0; i < s.length(); i++) {
                int idx = s.charAt(i) - 'A';
                check[idx]++;
                if (check[idx] == 3) {
                    sb.append(s.charAt(i));
                    sb.append(s.charAt(i));
                    check[idx] = 0;
                    i++;
                } else {
                    sb.append(s.charAt(i));
                }
            }
            if (sb.toString().equals(s)) bw.write("OK\n");
            else bw.write("FAKE\n");
        }
        bw.flush();
        bw.close();

    }
}