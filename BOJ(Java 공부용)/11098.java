import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            List<p> v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int price = Integer.parseInt(st.nextToken());
                String name = st.nextToken();
                v.add(new p(price, name));
            }
            v.sort((a, b) -> Integer.compare(b.price, a.price));
            bw.write(v.get(0).name + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static class p {
        int price;
        String name;

        private p(int price, String name) {
            this.price = price;
            this.name = name;
        }
    }
}