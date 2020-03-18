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
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        boolean[] visited = new boolean[n + 1];
        st = new StringTokenizer(br.readLine());
        int know = Integer.parseInt(st.nextToken());
        for (int i = 0; i < know; i++) {
            int num = Integer.parseInt(st.nextToken());
            visited[num] = true;
        }
        if (know == 0) {
            System.out.println(m);
        } else {
            List<List<Integer>> v = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int cnt = Integer.parseInt(st.nextToken());
                List<Integer> temp = new ArrayList<>();
                for (int j = 0; j < cnt; j++) {
                    temp.add(Integer.parseInt(st.nextToken()));
                }
                v.add(temp);
            }
            for (int k = 0; k < m; k++) {
                for (List<Integer> integers : v) {
                    boolean ok = false;
                    for (Integer value : integers) {
                        if (visited[value]) {
                            ok = true;
                            break;
                        }
                    }
                    if (ok) {
                        for (Integer integer : integers) {
                            visited[integer] = true;
                        }
                    }
                }
            }
            int cnt = 0;
            for (List<Integer> integers : v) {
                boolean ok = false;
                for (Integer integer : integers) {
                    if (visited[integer]) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) cnt++;
            }
            System.out.println(cnt);
        }
    }
}