import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //팰린드롬 -> 소수
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 2; i <= 9; i++) v.add(i);

        for (int i = 1; i <= 9999; i++) {
            StringBuilder sb = new StringBuilder();
            StringBuilder temp = new StringBuilder();
            //짝수팰린드롬
            sb.append(i);
            temp.append(i);
            sb.append(temp.reverse());
            v.add(Integer.parseInt(sb.toString()));
            if (i >= 1000) continue;
            //홀수팰린드롬
            for (int j = 0; j < 10; j++) {
                StringBuilder sb2 = new StringBuilder();
                StringBuilder temp2 = new StringBuilder();
                temp2.append(i);
                sb2.append(i);
                sb2.append(j);
                sb2.append(temp2.reverse());
                v.add(Integer.parseInt(sb2.toString()));
            }
        }
        Collections.sort(v);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < v.size(); i++) {
            int num = v.get(i);
            if (num < a) continue;
            if (num > b) break;
            if (go(num)) {
                ans.add(num);
            }
        }
        for (int i = 0; i < ans.size(); i++) bw.write(ans.get(i) + "\n");
        bw.write("-1");
        bw.flush();
        bw.close();
    }

    private static boolean go(int num) {
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}