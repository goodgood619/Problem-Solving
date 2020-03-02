import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken());
        int here = 0, total = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken()), g = Integer.parseInt(st.nextToken());
            total += (d - here);
            //신호를 기다려야 하는지, 갈수있는지
            boolean check = false;
            int temp = 0;
            while (true) {
                if (!check) {
                    int p = temp;
                    boolean yes = false;
                    for (int j = temp; j < temp + r; j++) {
                        p = j;
                        if (p == total) {
                            total += (temp + r - p);
                            yes = true;
                            break;
                        }
                    }
                    temp = p + 1;
                    if (yes) break;
                    check = true;
                } else {
                    int p = temp;
                    boolean yes = false;
                    for (int j = temp; j < temp + g; j++) {
                        p = j;
                        if (p == total) {
                            yes = true;
                            break;
                        }
                    }
                    temp = p + 1;
                    if (yes) break;
                    check = false;
                }
            }
            here = d;
        }
        total += (l - here);
        System.out.println(total);
    }
}