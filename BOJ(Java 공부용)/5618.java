import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        int max = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            max = max(max, arr[i]);
        }
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = max; i >= 1; i--) {
            boolean no = false;
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] % i != 0) {
                    no = true;
                    break;
                }
            }
            if (!no) v.add(i);
        }
        Collections.sort(v);
        for (int i = 0; i < v.size(); i++) bw.write(v.get(i) + "\n");
        bw.flush();
        bw.close();
    }
}