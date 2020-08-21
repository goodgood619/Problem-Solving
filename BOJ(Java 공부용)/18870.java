import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Integer> list = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int value = Integer.parseInt(st.nextToken());
            list.add(value);
            set.add(value);
        }
        int[] lowerList = new int[set.size()];
        Iterator<Integer> iterator = set.iterator();
        int idx = 0;
        while (iterator.hasNext()) {
            lowerList[idx++] = iterator.next();
        }
        Arrays.sort(lowerList);
        for (int value : list) {
            int ans = lowerbound(lowerList, 0, lowerList.length - 1, value);
            bw.write(ans + " ");
        }
        bw.flush();
        bw.close();
    }

    private static int lowerbound(int[] list, int left, int right, int target) {
        while (left < right) {
            int mid = (left + right) / 2;
            int value = list[mid];
            if (value < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
}