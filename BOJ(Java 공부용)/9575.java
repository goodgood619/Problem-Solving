import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> v = new ArrayList<>();
        go(0, 0, 7, v);
        Collections.sort(v);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            int cnt = 0;
            int[] a1 = new int[51];
            int[] a2 = new int[51];
            int[] a3 = new int[51];
            HashMap<Integer, Integer> m = new HashMap<>();
            int a = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= a; i++) a1[i] = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= b; i++) {
                a2[i] = Integer.parseInt(st.nextToken());
            }
            int c = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= c; i++) {
                a3[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) {
                    for (int k = 1; k <= c; k++) {
                        final int i1 = a1[i] + a2[j] + a3[k];
                        int idx = lowerbound(0, v.size(), i1, v);
                        if (v.get(idx) == i1 && m.get(v.get(idx)) == null) {
                            m.put(v.get(idx), 1);
                            cnt++;
                        }
                    }
                }
            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int lowerbound(int left, int right, int num, ArrayList<Integer> arr) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr.get(mid) < num) left = mid + 1;
            else right = mid;
        }
        return right;
    }

    private static void go(int sum, int index, int depth, ArrayList<Integer> v) {
        if (index == depth) return;
        v.add(sum);
        go(sum * 10 + 5, index + 1, depth, v);
        go(sum * 10 + 8, index + 1, depth, v);
    }
}