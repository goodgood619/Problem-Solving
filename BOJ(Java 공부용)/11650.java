import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        p[] arr = new p[n];
        for (int i = 0; i < n; i++) arr[i] = new p(0, 0);
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
            arr[i].x = x;
            arr[i].y = y;
        }
        Arrays.sort(arr, (a, b) -> {
            if (a.x < b.x) return -1;
            else if (a.x > b.x) return 1;
            else {
                if (a.y < b.y) return -1;
                else if (a.y > b.y) return 1;
                else return 0;
            }
        });
        for (int i = 0; i < arr.length; i++) {
            bw.write(arr[i].x + " " + arr[i].y + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}