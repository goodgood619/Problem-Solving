import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine()), cnt = 0;
            boolean[] visited = new boolean[n];
            List<P> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken());
                list.add(new P(first, second));
            }
            list.sort((a, b) -> {
                if (a.first < b.first) return -1;
                else if (a.first > b.first) return 1;
                else {
                    return Integer.compare(a.second, b.second);
                }
            });

            int second = list.get(0).second;
            for (int i = 0; i < n - 1; i++) {
                int fsecond = list.get(i).second, ssecond = list.get(i + 1).second;
                if (fsecond < ssecond) visited[i + 1] = true;
                else {
                    if (second < ssecond) visited[i + 1] = true;
                    else if (second > ssecond) {
                        second = ssecond;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (!visited[i]) cnt++;
            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }
}

class P {
    int first, second;

    P(int first, int second) {
        this.first = first;
        this.second = second;
    }
}