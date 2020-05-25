import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static long ans = (long) -1e18;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        List<Character> op = new ArrayList<>();
        List<Integer> nums = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+' || s.charAt(i) == '-' || s.charAt(i) == '*') op.add(s.charAt(i));
            else nums.add(s.charAt(i) - '0');
        }
        dfs(nums.get(0), 0, op, nums);
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void dfs(long result, int curopidx, List<Character> op, List<Integer> nums) {
        if (curopidx >= op.size()) {
            ans = Math.max(ans, result);
            return;
        }
        long res1 = calc(op.get(curopidx), result, nums.get(curopidx + 1));
        dfs(res1, curopidx + 1, op, nums);
        if (curopidx + 1 < op.size()) {
            long res2 = calc(op.get(curopidx + 1), nums.get(curopidx + 1), nums.get(curopidx + 2));
            dfs(calc(op.get(curopidx), result, res2), curopidx + 2, op, nums);
        }
    }

    private static long calc(char c, long n1, long n2) {
        if (c == '+') return n1 + n2;
        else if (c == '-') return n1 - n2;
        else return n1 * n2;
    }
}