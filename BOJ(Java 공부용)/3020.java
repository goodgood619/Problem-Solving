import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), h = Integer.parseInt(st.nextToken());
        List<Integer> v = new ArrayList<>();
        List<Integer> v2 = new ArrayList<>();
        for (int i = 0; i < n / 2; i++) {
            int first = Integer.parseInt(br.readLine()), second = Integer.parseInt(br.readLine());
            v.add(first);
            v2.add(second);
        }
        Collections.sort(v);
        Collections.sort(v2);
        int min = (int) 1e9;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 1; i <= h; i++) {
            int ans1 = -1, ans2 = -1;
            int idx1 = lowerbound(0, v.size(), v, i);
            int idx2 = lowerbound(0, v2.size(), v2, h - i + 1);
            if (idx1 == v.size()) ans1 = 0;
            else ans1 = v.size() - idx1;
            if (idx2 == v2.size()) ans2 = 0;
            else ans2 = v2.size() - idx2;
            if (min > ans1 + ans2) {
                min = ans1 + ans2;
                map.put(min, 1);
            } else if (min == ans1 + ans2) {
                int value = map.get(min);
                value++;
                map.remove(min);
                map.put(min, value);
            }
        }
        bw.write(min + " " + map.get(min) + "");
        bw.flush();
        bw.close();
    }

    private static int lowerbound(int left, int right, List<Integer> v, int num) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (v.get(mid) < num) left = mid + 1;
            else right = mid;
        }
        return right;
    }
}