import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        String[] input = br.readLine().split(",");
        int[] arr = new int[n];
        for (int i = 0; i < input.length; i++) arr[i] = Integer.parseInt(input[i]);
        for (int i = 0; i < k; i++) {
            int[] temp = new int[n];
            int idx = 0;
            for (int j = 0; j < arr.length - 1; j++) {
                temp[idx++] = arr[j + 1] - arr[j];
            }
            arr = temp;
        }
        for (int i = 0; i < arr.length - k; i++) {
            if (i == arr.length - k - 1) {
                bw.write(arr[i] + "\n");
            } else bw.write(arr[i] + ",");
        }
        bw.flush();
        bw.close();
    }
}