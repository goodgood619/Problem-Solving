import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

import static java.lang.Integer.min;
import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        p[] arr = new p[n];
        for (int i = 0; i < arr.length; i++) arr[i] = new p(0, 0);
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), color = Integer.parseInt(st.nextToken());
            arr[i].here = here;
            arr[i].color = color;
        }
        Arrays.sort(arr, (a, b) -> {
            if (a.here < b.here) return -1;
            else if (a.here > b.here) return 1;
            else {
                if (a.color < b.color) return -1;
                else if (a.color > b.color) return 1;
                else return 0;
            }
        });

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int here = arr[i].here;
            int color = arr[i].color;
            int min = (int) 1e9;
            for (int j = 0; j < n; j++) {
                if (i == j || color != arr[j].color) continue;
                min = min(min, abs(here - arr[j].here));
            }
            sum += min;
        }
        bw.write(sum + " ");
        bw.flush();
        bw.close();
    }

    private static class p {
        int here, color;

        private p(int here, int color) {
            this.here = here;
            this.color = color;
        }
    }
}