import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Integer, String> map1 = new HashMap<>();
        HashMap<String, Integer> map2 = new HashMap<>();
        map1.put(0, "zero");
        map1.put(1, "one");
        map1.put(2, "two");
        map1.put(3, "three");
        map1.put(4, "four");
        map1.put(5, "five");
        map1.put(6, "six");
        map1.put(7, "seven");
        map1.put(8, "eight");
        map1.put(9, "nine");
        map2.put("zero", 0);
        map2.put("one", 1);
        map2.put("two", 2);
        map2.put("three", 3);
        map2.put("four", 4);
        map2.put("five", 5);
        map2.put("six", 6);
        map2.put("seven", 7);
        map2.put("eight", 8);
        map2.put("nine", 9);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
        ArrayList<String> v = new ArrayList<>();
        for (int i = m; i <= n; i++) {
            if (i <= 9) {
                v.add(map1.get(i));
            } else {
                StringBuilder sb = new StringBuilder();
                int one = i / 10, two = i % 10;
                sb.append(map1.get(one));
                sb.append(' ');
                sb.append(map1.get(two));
                v.add(sb.toString());
            }
        }
        Collections.sort(v);
        for (int i = 0; i < v.size(); i++) {
            String s = v.get(i);
            int num = 0;
            if (s.length() <= 5) {
                num = map2.get(s);
            } else {
                String[] input = s.split(" ");
                int one = map2.get(input[0]), two = map2.get(input[1]);
                num = one * 10 + two;
            }
            if (i % 10 == 9) {
                bw.write(num + " ");
                bw.write("\n");
            } else {
                bw.write(num + " ");
            }
        }
        bw.flush();
        bw.close();
    }
}