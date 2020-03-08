import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] arr = new int[4];
        arr[1] = 1;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            go(arr, c);
        }
        for (int i = 1; i <= 3; i++) {
            if (arr[i] == 1) System.out.println(i);
        }
    }

    private static void go(int[] arr, char c) {
        if (c == 'A') {
            int temp = arr[1];
            arr[1] = arr[2];
            arr[2] = temp;
        } else if (c == 'B') {
            int temp = arr[2];
            arr[2] = arr[3];
            arr[3] = temp;
        } else {
            int temp = arr[1];
            arr[1] = arr[3];
            arr[3] = temp;
        }
    }
}