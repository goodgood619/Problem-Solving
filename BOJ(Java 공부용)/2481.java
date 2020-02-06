import java.io.*;
import java.util.*;

import static java.lang.Math.pow;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        p[] anspo = new p[n + 1];
        for (int i = 0; i <= n; i++) anspo[i] = new p(0, 0, 0);
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            String s = br.readLine();
            int sum = 0;
            for (int j = s.length() - 1; j >= 0; j--) {
                int value = s.charAt(j) - '0';
                sum += value * pow(2, s.length() - j - 1);
            }
            map.put(sum, i);
            anspo[i].first = sum;
            anspo[i].second = i;
            anspo[i].third = s.length();
        }
        for (int i = 1; i < anspo.length; i++) {
            int value = anspo[i].first;
            int index = anspo[i].second;
            int length = anspo[i].third;
            int p = 0, v = value, xor = 1;
            while (p != length) {
                v ^= xor;
                if (map.get(v) != null) {
                    graph[index].add(map.get(v));
                }
                xor *= 2;
                p++;
                v = value;
            }
        }
        int start = anspo[1].second;
        st = new StringTokenizer(br.readLine());
        int j = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= j; i++) {
            int[] path = new int[n + 1];
            ArrayList<Integer> path2 = new ArrayList<>();
            int end = Integer.parseInt(br.readLine());
            boolean[] visited = new boolean[n + 1];
            if (!bfs(start, visited, graph, path, end)) bw.write("-1\n");
            else {
                go(end, path, path2);
                path2.add(end);
                for (int p = 0; p < path2.size(); p++) bw.write(path2.get(p) + " ");
                bw.write("\n");
            }
        }
        bw.flush();
        bw.close();
    }

    private static void go(int end, int[] path, ArrayList<Integer> path2) {
        if (path[end] == 0) return;
        go(path[end], path, path2);
        path2.add(path[end]);
    }

    private static boolean bfs(int h, boolean[] visited, ArrayList<Integer>[] graph, int[] path, int end) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(h);
        visited[h] = true;
        while (!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            if (here == end) return true;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i);
                if (!visited[next]) {
                    visited[next] = true;
                    q.add(next);
                    path[next] = here;
                }
            }
        }
        return false;
    }

    private static class p {
        int first, second, third;

        private p(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }
}