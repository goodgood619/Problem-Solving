import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int counter = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        StringBuilder origin = new StringBuilder();
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            origin.append(arr[i]);
        }
        Arrays.sort(arr);
        Map<Integer, Integer> map1 = new HashMap<>();
        Map<Integer, Integer> map2 = new HashMap<>();
        boolean[] visited = new boolean[n];
        StringBuilder sb = new StringBuilder();
        go(0, n, arr, visited, map1, map2, sb);
        for (int i = 0; i < arr.length; i++) sb.append(arr[i]);
        int end = map1.get(Integer.parseInt(sb.toString()));
        int start = map1.get(Integer.parseInt(origin.toString()));
        if (start == end) {
            System.out.println(0);
            return;
        }
        bfs(start, end, map1, map2, k);
    }

    private static void bfs(int start, int end, Map<Integer, Integer> map1, Map<Integer, Integer> map2, int k) throws IOException {
        Deque<Integer> q = new ArrayDeque<>();
        boolean[] visited = new boolean[41000];
        int[] dist = new int[41000];
        q.add(map2.get(start));
        visited[start] = true;
        while (!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            String s = String.valueOf(here);
            for (int i = 0; i < s.length() - (k - 1); i++) {
                if (i + k - 1 >= s.length()) continue;
                StringBuilder sb = new StringBuilder();
                // 처음 ~ i전까지(순차적 넣기)
                for (int j = 0; j < i; j++) {
                    sb.append(s.charAt(j));
                }
                // i~i+k-1까지(뒤집은 상태)
                for (int j = i + k - 1; j >= i; j--) {
                    sb.append(s.charAt(j));
                }
                // i+k부터 끝까지(순차적 넣기)
                for (int j = i + k; j < s.length(); j++) {
                    sb.append(s.charAt(j));
                }
                int next = map1.get(Integer.parseInt(sb.toString()));
                if (!visited[next]) {
                    visited[next] = true;
                    q.add(map2.get(next));
                    dist[next] = dist[map1.get(here)] + 1;
                }
            }
        }
        if (dist[end] == 0) bw.write("-1");
        else bw.write(dist[end] + " ");
        bw.flush();
        bw.close();
    }

    private static void go(int cnt, int depth, int[] arr, boolean[] visited, Map<Integer, Integer> map1, Map<Integer, Integer> map2, StringBuilder sb) {
        if (cnt == depth) {
            int num = Integer.parseInt(sb.toString());
            map1.put(num, counter);
            map2.put(counter++, num);
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sb.append(arr[i]);
                go(cnt + 1, depth, arr, visited, map1, map2, sb);
                sb.deleteCharAt(sb.length() - 1);
                visited[i] = false;
            }
        }
    }
}