import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String oh = br.readLine();
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[4];
        for (int i = 0; i < oh.length(); i++) {
            if (oh.charAt(i) == 'L') arr[0]++;
            if (oh.charAt(i) == 'O') arr[1]++;
            if (oh.charAt(i) == 'V') arr[2]++;
            if (oh.charAt(i) == 'E') arr[3]++;
        }
        ArrayList<p> V = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int l = arr[0], o = arr[1], v = arr[2], e = arr[3];
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == 'L') l++;
                if (s.charAt(j) == 'O') o++;
                if (s.charAt(j) == 'V') v++;
                if (s.charAt(j) == 'E') e++;
            }
            int sum = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
            V.add(new p(sum, s));
        }
        V.sort((a, b) -> {
            if (a.sum > b.sum) return -1;
            else if (a.sum < b.sum) return 1;
            else {
                return a.s.compareTo(b.s);
            }
        });
        bw.write(V.get(0).s);
        bw.flush();
        bw.close();
    }

    private static class p {
        int sum;
        String s;

        private p(int sum, String s) {
            this.sum = sum;
            this.s = s;
        }
    }
}