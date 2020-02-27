import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("n " + 'e');
        System.out.println("- -----------");
        for (int i = 0; i < 10; i++) {
            if (i == 0 || i == 1) {
                System.out.print(i + " " + String.format("%.0f", go(i)));
            } else if (i == 2) {
                System.out.print(i + " " + String.format("%.1f", go(i)));
            } else System.out.print(i + " " + String.format("%.9f", go(i)));
            System.out.println();
        }
    }

    private static double go(int n) {
        double a = 0;
        for (int i = 0; i <= n; i++) {
            a += 1.0 / fact(i);
        }
        return a;
    }

    private static int fact(int x) {
        if (x == 0) return 1;
        return fact(x - 1) * x;
    }
}