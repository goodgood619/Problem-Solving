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
        st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        ArrayList<p> v = new ArrayList<>();
        for (int i = 1; i <= m; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (v.size() < n) {
                boolean ok = false;
                for (int j = 0; j < v.size(); j++) {
                    if (v.get(j).first == num) {
                        v.get(j).second++;
                        ok = true;
                        break;
                    }
                }
                if (ok) continue;
                v.add(new p(num, 1, i));
            } else {
                boolean ok = false;
                for (int j = 0; j < v.size(); j++) {
                    if (v.get(j).first == num) {
                        v.get(j).second++;
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    int min = (int) 1e9, idx = (int) 1e9, ridx = 0;
                    for (int j = 0; j < v.size(); j++) {
                        if (min > v.get(j).second) {
                            min = v.get(j).second;
                        }
                    }
                    for (int j = 0; j < v.size(); j++) {
                        if (min == v.get(j).second) {
                            if (idx > v.get(j).third) {
                                idx = v.get(j).third;
                                ridx = j;
                            }
                        }
                    }
                    v.remove(ridx);
                    v.add(new p(num, 1, i));
                }
            }
        }
        v.sort((a, b) -> {
            if (a.first < b.first) return -1;
            else if (a.first > b.first) return 1;
            else {
                if (a.second < b.second) return -1;
                else if (a.second > b.second) return 1;
                else {
                    if (a.third < b.third) return -1;
                    else if (a.third > b.third) return 1;
                    else return 0;
                }
            }
        });
        for (int i = 0; i < v.size(); i++) bw.write(v.get(i).first + " ");
        bw.flush();
        bw.close();
    }

    private static class p {
        int first, second, third;

        private p(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }
}