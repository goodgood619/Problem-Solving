import java.io.*;
import java.util.HashMap;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        HashMap<String, Integer> dom = new HashMap<>();
        HashMap<String, Integer> kat = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            if (dom.get(s) == null) {
                dom.put(s, 1);
            } else {
                int value = dom.get(s);
                value++;
                dom.remove(s);
                dom.put(s, value);
            }
        }
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            if (kat.get(s) == null) {
                kat.put(s, 1);
            } else {
                int value = kat.get(s);
                value++;
                kat.remove(s);
                kat.put(s, value);
            }
        }
        int sum = 0;
        for (String s : dom.keySet()) {
            int value = dom.get(s);
            if (kat.get(s) == null) continue;
            else {
                sum += min(kat.get(s), value);
            }
        }
        System.out.println(sum);
    }
}