import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static BigInteger ans = new BigInteger("2").pow(500);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        p[] arr = new p[n];
        for (int i = 0; i < n; i++) arr[i] = new p(0, 0);
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            long sin = Long.parseLong(st.nextToken()), dan = Long.parseLong(st.nextToken());
            arr[i].sin = sin;
            arr[i].dan = dan;
        }

        for (int i = 1; i <= n; i++) {
            boolean[] visited = new boolean[n];
            go(0, 0, i, arr, visited);
        }
        bw.write(ans.toString() + " ");
        bw.flush();
        bw.close();
    }

    private static void go(int here, int cnt, int depth, p[] arr, boolean[] visited) {
        if (cnt == depth) {
            BigInteger sinsin = new BigInteger("1"), dandan = new BigInteger("0");
            for (int i = 0; i < arr.length; i++) {
                if (visited[i]) {
                    sinsin = sinsin.multiply(new BigInteger(String.valueOf(arr[i].sin)));
                    dandan = dandan.add(new BigInteger(String.valueOf(arr[i].dan)));
                }
            }
            sinsin = sinsin.subtract(dandan);
            if (sinsin.compareTo(BigInteger.ZERO) < 0) sinsin = sinsin.multiply(new BigInteger("-1"));
            if (ans.compareTo(sinsin) > 0) ans = sinsin;
            return;
        }
        for (int i = here; i < visited.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                go(i + 1, cnt + 1, depth, arr, visited);
                visited[i] = false;
            }
        }
    }

    private static class p {
        long sin, dan;

        private p(long sin, long dan) {
            this.sin = sin;
            this.dan = dan;
        }
    }
}