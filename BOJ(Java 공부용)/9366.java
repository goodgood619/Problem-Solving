import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        int Case = 1;
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int[] arr = new int[3];
            for (int i = 0; i < 3; i++) arr[i] = Integer.parseInt(st.nextToken());
            Arrays.sort(arr);
            if (arr[0] + arr[1] <= arr[2]) bw.write("Case #" + Case + ": invalid!\n");
            else {
                if (arr[0] == arr[1] && arr[1] == arr[2]) bw.write("Case #" + Case + ": equilateral\n");
                else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[2] == arr[0])
                    bw.write("Case #" + Case + ": isosceles\n");
                else bw.write("Case #" + Case + ": scalene\n");
            }
            Case++;
        }
        bw.flush();
        bw.close();
    }
}