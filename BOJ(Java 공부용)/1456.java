import java.io.*;
import java.util.*;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        boolean[] check = new boolean[10000001];
        for (int i = 2; i <= sqrt(10000000); i++) {
            if (check[i]) continue;
            for (int j = i * i; j <= 10000000; j += i) {
                check[j] = true;
            }
        }
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 2; i <= 10000000; i++) {
            if (!check[i]) v.add(i);
        }
        long a = Long.parseLong(st.nextToken()), b = Long.parseLong(st.nextToken());
        ArrayList<Long> ans = new ArrayList<>();
        for (int i = 0; i < v.size(); i++) {
            long here = v.get(i);
            if (here > b) break;
            for (int j = 2; pow(here, j) <= b; j++) {
                long temp = (long) pow(here, j);
                if (temp > b) break;
                ans.add(temp);
            }
        }

        Collections.sort(ans);
        int idx = lowerbound(0, ans.size(), a, ans);
        System.out.println(ans.size() - idx);
    }

    private static int lowerbound(int left, int right, long num, ArrayList<Long> arr) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr.get(mid) < num) left = mid + 1;
            else right = mid;
        }
        return right;
    }
}