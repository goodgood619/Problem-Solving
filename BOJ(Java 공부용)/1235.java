import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<String> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            v.add(br.readLine());
        }
        int length = v.get(0).length(), k = 1;
        for (int i = length - 1; i >= 0; i--) {
            HashSet<String> set = new HashSet<>();
            for (int j = 0; j < v.size(); j++) {
                set.add(v.get(j).substring(i, length));
            }
            if (set.size() == n) {
                System.out.println(k);
                return;
            }
            k++;
        }
    }
}