import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<p> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken());
            v.add(new p(i + 1, s, c, l));
        }
        v.sort((a, b) -> {
            if (a.second > b.second) return -1;
            else if (a.second < b.second) return 1;
            else {
                if (a.third < b.third) return -1;
                else if (a.third > b.third) return 1;
                else {
                    if (a.four < b.four) return -1;
                    else if (a.four > b.four) return 1;
                    else return 0;
                }
            }
        });
        System.out.println(v.get(0).first);
    }

    private static class p {
        int first, second, third, four;

        private p(int first, int second, int third, int four) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.four = four;
        }
    }
}