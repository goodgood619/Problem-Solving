import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        p[] arr = new p[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new p(0, 0);
            st = new StringTokenizer(br.readLine());
            arr[i].first = Integer.parseInt(st.nextToken());
            arr[i].second = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr, (a, b) -> {
            if (a.first < b.first) return -1;
            else if (a.first > b.first) return 1;
            else {
                if (a.second < b.second) return -1;
                else if (a.second > b.second) return 1;
                else return 0;
            }
        });

        int first = arr[0].first, second = arr[0].second;
        long sum = second - first;
        for (int i = 1; i < n; i++) {
            int nextfirst = arr[i].first, nextsecond = arr[i].second;
            if (first <= nextfirst && second <= nextsecond && nextfirst <= second) {
                sum += (nextsecond - second);
                second = nextsecond;
            } else if (nextfirst > second) {
                first = nextfirst;
                second = nextsecond;
                sum += (second - first);
            }
        }
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }

    private static class p {
        int first, second;

        private p(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}