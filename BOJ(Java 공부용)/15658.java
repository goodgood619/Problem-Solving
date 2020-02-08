import java.io.*;
import java.util.*;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static int min = (int) 2e9, max = (int) -2e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int plus = Integer.parseInt(st.nextToken()), minus = Integer.parseInt(st.nextToken()), multiply = Integer.parseInt(st.nextToken()), divide = Integer.parseInt(st.nextToken());

        go(1, arr[0], plus, minus, multiply, divide, arr);
        bw.write(max + "\n" + min + " ");
        bw.flush();
        bw.close();
    }

    private static void go(int index, int sum, int plus, int minus, int multiply, int divide, int[] arr) {
        if (index == arr.length) {
            max = max(max, sum);
            min = min(min, sum);
            return;
        }
        if (plus != 0) go(index + 1, sum + arr[index], plus - 1, minus, multiply, divide, arr);
        if (minus != 0) go(index + 1, sum - arr[index], plus, minus - 1, multiply, divide, arr);
        if (multiply != 0) go(index + 1, sum * arr[index], plus, minus, multiply - 1, divide, arr);
        if (divide != 0) go(index + 1, sum / arr[index], plus, minus, multiply, divide - 1, arr);
    }
}