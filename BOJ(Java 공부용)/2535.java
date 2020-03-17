import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<p> v = new ArrayList<>();
        int n = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int nation = Integer.parseInt(st.nextToken()), num = Integer.parseInt(st.nextToken()), score = Integer.parseInt(st.nextToken());
            v.add(new p(nation, num, score));
        }
        v.sort((a, b) -> Integer.compare(b.score, a.score));
        int[] same = new int[n + 1];
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            int nation = v.get(i).nation, num = v.get(i).num;
            if (cnt == 3) break;
            if (same[nation] >= 2) continue;
            same[nation]++;
            bw.write(nation + " " + num + "\n");
            cnt++;
        }
        bw.flush();
        bw.close();
    }
}

class p {
    int nation, num, score;

    p(int nation, int num, int score) {
        this.nation = nation;
        this.num = num;
        this.score = score;
    }
}