import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.StrictMath.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Double> v = new ArrayList<>();
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int e = Integer.parseInt(st.nextToken()), f = Integer.parseInt(st.nextToken());
        p[] arr = new p[3];
        for (int i = 0; i < 3; i++) arr[i] = new p(0, 0);

        arr[0].left = Math.min(a, b);
        arr[0].right = Math.max(a, b);
        arr[1].left = Math.min(c, d);
        arr[1].right = Math.max(c, d);
        arr[2].left = Math.min(e, f);
        arr[2].right = Math.max(e, f);
        double mid = 0, left = 0, right = n;
        if (arr[0].left != arr[0].right) {
            mid = (arr[0].left + arr[0].right) / 2.0;
            double temp = mid - left;
            if (arr[1].left < mid) arr[1].left = mid + (mid - arr[1].left);
            if (arr[1].right < mid) arr[1].right = mid + (mid - arr[1].right);
            if (arr[2].left < mid) arr[2].left = mid + (mid - arr[2].left);
            if (arr[2].right < mid) arr[2].right = mid + (mid - arr[2].right);
            left = mid;
            right = max(right, mid + temp);
        }
        if (arr[1].left != arr[1].right) {
            mid = (arr[1].left + arr[1].right) / 2.0;
            double temp = mid - left;
            if (arr[2].left < mid) arr[2].left = mid + (mid - arr[2].left);
            if (arr[2].right < mid) arr[2].right = mid + (mid - arr[2].right);
            left = mid;
            right = max(right, mid + temp);
        }
        if (arr[2].left != arr[2].right) {
            mid = (arr[2].left + arr[2].right) / 2.0;
            double temp = mid - left;
            left = mid;
            right = max(right, mid + temp);
        }
        System.out.println(String.format("%.1f", (right - left)));
    }

    static class p {
        double left, right;

        p(double left, double right) {
            this.left = left;
            this.right = right;
        }
    }
}