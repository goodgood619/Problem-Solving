import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken()), w = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
            int cnt = 0;
            for (int j = 0; j < w; j++) {
                for (int i = 0; i < h; i++) {
                    cnt++;
                    if (cnt == n) {
                        if (j >= 9) {
                            StringBuilder sb = new StringBuilder();
                            sb.append((i + 1));
                            sb.append((j + 1));
                            System.out.println(sb.toString());
                            break;
                        } else {
                            StringBuilder sb = new StringBuilder();
                            sb.append((i + 1));
                            sb.append(0);
                            sb.append((j + 1));
                            System.out.println(sb.toString());
                            break;
                        }
                    }
                }
                if (cnt == n) break;
            }
        }
    }
}