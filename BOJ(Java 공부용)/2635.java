import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()), max = 0;
        ArrayList<Integer> temp = new ArrayList<>();
        for (int i = n; i >= 1; i--) {
            ArrayList<Integer> v = new ArrayList<>();
            v.add(n);
            v.add(i);
            while (true) {
                int num = v.get(v.size() - 2) - v.get(v.size() - 1);
                if (num < 0) break;
                v.add(num);
            }
            if (max < v.size()) {
                max = v.size();
                temp = v;
            }
        }
        bw.write(temp.size() + "\n");
        for (int i = 0; i < temp.size(); i++) bw.write(temp.get(i) + " ");
        bw.flush();
        bw.close();
    }
}