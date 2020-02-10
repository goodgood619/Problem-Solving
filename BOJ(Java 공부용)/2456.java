import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        p[] arr = new p[3];
        for (int i = 0; i < 3; i++) arr[i] = new p(0, 0, 0, 0, i);
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int one = Integer.parseInt(st.nextToken()), two = Integer.parseInt(st.nextToken()), three = Integer.parseInt(st.nextToken());
            arr[0].total += one;
            arr[1].total += two;
            arr[2].total += three;
            if (one == 1) arr[0].one++;
            if (one == 2) arr[0].two++;
            if (one == 3) arr[0].three++;
            if (two == 1) arr[1].one++;
            if (two == 2) arr[1].two++;
            if (two == 3) arr[1].three++;
            if (three == 1) arr[2].one++;
            if (three == 2) arr[2].two++;
            if (three == 3) arr[2].three++;
        }
        Arrays.sort(arr, (a, b) -> {
            if (a.total > b.total) return -1;
            else if (a.total < b.total) return 1;
            else {
                if (a.three > b.three) return -1;
                else if (a.three < b.three) return 1;
                else {
                    if (a.two > b.two) return -1;
                    else if (a.two < b.two) return 1;
                    else {
                        if (a.one > b.one) return -1;
                        else if (a.one < b.one) return 1;
                        else return 0;
                    }
                }
            }
        });

        if (arr[0].total == arr[1].total && arr[0].three == arr[1].three && arr[0].two == arr[1].two && arr[0].one == arr[1].one) {
            bw.write("0" + " " + arr[0].total + "\n");
        } else bw.write((arr[0].index + 1) + " " + arr[0].total + "\n");
        bw.flush();
        bw.close();
    }

    private static class p {
        int one, two, three, total, index;

        private p(int one, int two, int three, int total, int index) {
            this.one = one;
            this.two = two;
            this.three = three;
            this.total = total;
            this.index = index;
        }
    }
}