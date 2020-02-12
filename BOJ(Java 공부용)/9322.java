import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] arr = new String[n];
            String[] output = new String[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) arr[i] = st.nextToken();
            st = new StringTokenizer(br.readLine());
            p[] idx = new p[n];
            for (int i = 0; i < n; i++) idx[i] = new p(0, 0);
            for (int i = 0; i < n; i++) {
                String find = st.nextToken();
                for (int j = 0; j < arr.length; j++) {
                    if (find.equals(arr[j])) {
                        idx[i].here = i;
                        idx[i].next = j;
                        break;
                    }
                }
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                String s = st.nextToken();
                output[idx[i].next] = s;
            }
            for (int i = 0; i < output.length; i++) {
                bw.write(output[i] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    private static class p {
        int here, next;

        private p(int here, int next) {
            this.here = here;
            this.next = next;
        }
    }
}