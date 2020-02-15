import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        k--;
        st = new StringTokenizer(br.readLine());
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 0; i < n; i++) v.add(Integer.parseInt(st.nextToken()));
        Collections.sort(v);
        System.out.println(v.get(k));
    }
}