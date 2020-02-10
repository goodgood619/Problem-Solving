import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        HashMap<Integer, Integer> cnt = new HashMap<>();
        HashMap<Integer, Integer> first = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (first.get(num) == null) {
                first.put(num, i);
            }
            if (cnt.get(num) == null) {
                cnt.put(num, 1);
            } else {
                int value = cnt.get(num);
                value++;
                cnt.remove(num);
                cnt.put(num, value);
            }
        }
        Iterator it = cnt.keySet().iterator();
        ArrayList<p> v = new ArrayList<>();
        while (it.hasNext()) {
            int key = (int) it.next();
            int cntvalue = cnt.get(key);
            int firstindex = first.get(key);
            v.add(new p(key, cntvalue, firstindex));
        }
        v.sort((a, b) -> {
            if (a.cnt > b.cnt) return -1;
            else if (a.cnt < b.cnt) return 1;
            else {
                if (a.index < b.index) return -1;
                else if (a.index > b.index) return 1;
                else return 0;
            }
        });

        for (int i = 0; i < v.size(); i++) {
            int num = v.get(i).num;
            for (int j = 0; j < v.get(i).cnt; j++) {
                bw.write(num + " ");
            }
        }
        bw.flush();
        bw.close();
    }

    private static class p {
        int num, cnt, index;

        private p(int num, int cnt, int index) {
            this.num = num;
            this.cnt = cnt;
            this.index = index;
        }
    }

}