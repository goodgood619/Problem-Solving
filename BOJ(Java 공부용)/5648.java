import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};
    static int ans = (int) 1e9;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = sc.nextInt();
        List<Long> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            String s = sc.next();
            sb.append(s);
            v.add(Long.parseLong(sb.reverse().toString()));
        }
        Collections.sort(v);
        for (int i = 0; i < v.size(); i++) bw.write(v.get(i) + "\n");
        bw.flush();
        bw.close();
    }
}