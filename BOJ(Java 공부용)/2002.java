import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<p> v = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();
        ArrayList<p> second = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            v.add(new p(s, i));
            map.put(s, i);
        }
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            second.add(new p(s, map.get(s)));
        }
        int cnt = 0;
        for (int i = 0; i < second.size(); i++) {
            int preindex = v.get(0).index;
            int curindex = second.get(i).index;
            if (preindex == curindex) {
                v.remove(0);
                continue;
            } else {
                for (int j = 0; j < v.size(); j++) {
                    if (curindex == v.get(j).index) {
                        v.remove(j);
                        break;
                    }
                }
                cnt++;
            }
        }
        bw.write(cnt + " ");
        bw.flush();
        bw.close();
    }

    private static class p {
        String car;
        int index;

        private p(String car, int index) {
            this.car = car;
            this.index = index;
        }
    }
}