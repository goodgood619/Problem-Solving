import java.io.*;
import java.util.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        boolean[] num = new boolean[10000];
        int end = (int) 1e9;
        List<Integer> v = new ArrayList<>();
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < 4; i++) v.add(Integer.parseInt(st.nextToken()));
        for (int i = 0; i < 4; i++) {
            List<Integer> temp = new ArrayList<>();
            for (int j = i, p = 0; p < 4; j++, p++) {
                j %= 4;
                temp.add(v.get(j));
            }
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < temp.size(); j++) {
                sb.append(temp.get(j));
            }
            num[Integer.parseInt(sb.toString())] = true;
            end = min(end, Integer.parseInt(sb.toString()));
        }
        int cnt = 1;
        for (int i = 1111; i <= end; i++) {
            if (num[i] || i % 10 == 0 || i / 10 % 10 == 0 || i / 100 % 10 == 0) continue;
            else {
                cnt++;
                List<Integer> temp = new ArrayList<>();
                temp.add(i / 1000);
                temp.add(i / 100 % 10);
                temp.add(i / 10 % 10);
                temp.add(i % 10);
                for (int j = 0; j < 4; j++) {
                    List<Integer> temp2 = new ArrayList<>();
                    for (int k = j, p = 0; p < 4; p++, k++) {
                        k %= 4;
                        temp2.add(temp.get(k));
                    }
                    StringBuilder sb = new StringBuilder();
                    for (int k = 0; k < temp2.size(); k++) {
                        sb.append(temp2.get(k));
                    }
                    num[Integer.parseInt(sb.toString())] = true;
                }
            }
        }
        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}