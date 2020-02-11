import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        HashMap<Integer, Integer> map = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        // a정렬
        Arrays.sort(arr);
        // hashmap 순서대로 삽입
        for (int i = 0; i < n; i++) {
            map.put(arr[i], 1);
        }
        st = new StringTokenizer(br.readLine());
        // b에서 있는 key값들을 제거
        for (int i = 0; i < m; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (map.get(num) != null) {
                map.remove(num);
            }
        }
        // 출력
        if (map.size() == 0) {
            System.out.println(0);
            return;
        }
        System.out.println(map.size());
        int[] ans = new int[map.size()];
        int idx = 0;
        for (Integer integer : map.keySet()) {
            ans[idx++] = integer;
        }
        Arrays.sort(ans);
        for (int i = 0; i < ans.length; i++) {
            bw.write(ans[i] + " ");
        }
        bw.flush();
        bw.close();
    }
}