import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

import static java.lang.Integer.max;
import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> v = new ArrayList<>();
        int sum = 0;
        int[] arr = new int[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
            v.add(sum);
        }

        Collections.sort(v);
        int min = (int) 1e9, num = 0;

        for (int i = 0; i < v.size(); i++) {
            if (min > abs(100 - v.get(i))) {
                min = abs(100 - v.get(i));
                num = v.get(i);
            } else if (min == abs(v.get(i) - 100)) num = max(num, v.get(i));
        }
        System.out.println(num);
    }

}